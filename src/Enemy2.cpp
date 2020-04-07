#include "Enemy2.h"
#include "TextureManager.h"
#include "game.h"
#include "BulletManager.h"

Enemy2::Enemy2()
	:m_maxSpeed(2.5f), m_name("enemy2"), m_alpha(255),
	 m_fireRate(100.0f),m_coolTime(0.0f), m_activated(false)
{
	std::string imagePath = "../Assets/textures/enemy2.png";
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setType(ENEMY);
	setVelocity(glm::vec2(-1.0f * m_maxSpeed, 0.0f));
	std::cout << "Enemy2 instantiated!\n";
}

Enemy2::~Enemy2()
= default;

void Enemy2::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Enemy2::update()
{
	move();
	fire();
	if(m_coolTime > 0)
	{
		--m_coolTime;
	}
}

void Enemy2::clean()
{
}

void Enemy2::activate(bool newState)
{
	m_activated = newState;
}

bool Enemy2::isActivated()
{
	return m_activated;
}

void Enemy2::setTarget(glm::vec2 target)
{
	m_target = target;
	float tX = target.x;
	float tY = target.y;
	float baseSpeed = 10.0f;

	float difX = glm::abs(getPosition().x - tX), difY = glm::abs(getPosition().y - tY);

	bool xIsCloser = difX > difY;
	switch (xIsCloser)
	{
	case true:
		m_laserSpeed.x = baseSpeed;
		m_laserSpeed.y = difY / difX * baseSpeed;
		break;
	case false:
		m_laserSpeed.y = baseSpeed;
		m_laserSpeed.x = difX / difY * baseSpeed;
		break;
	}
	m_laserSpeed.x = getPosition().x > tX ? -m_laserSpeed.x : m_laserSpeed.x;
	m_laserSpeed.y =  getPosition().y > tY ? -m_laserSpeed.y : m_laserSpeed.y;
}

void Enemy2::move()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;

	setPosition(glm::vec2(deltax, deltay));
}

void Enemy2::fire()
{
	if (m_coolTime <= 0)
	{
		m_pLaser = BulletManager::Instance()->getEnemyBullet();
		m_pLaser->switchToEnemyLaser();
		m_pLaser->setPosition
		(glm::vec2(getPosition().x - 10.0f, getPosition().y));
		m_pLaser->setVelocity(m_laserSpeed);
		m_pLaser->activate(true);
		SoundManager::Instance()->playSound("enemyLaser", 0);
		m_coolTime = m_fireRate;
	}
}

void Enemy2::checkBound()
{
	if (getPosition().x <= Config::SCREEN_WIDTH * 0.03f - getWidth())
	{
		m_activated = false;
	}
	if (getPosition().y <= Config::SCREEN_HEIGHT * 0.03f - getHeight())
	{
		m_activated = false;
	}
	if (getPosition().y >= Config::SCREEN_HEIGHT * 0.97f + getHeight())
	{
		m_activated = false;
	}
}
