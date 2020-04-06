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
		auto bullet = BulletManager::Instance()->getEnemyBullet();
		bullet->switchToEnemyLaser();
		bullet->setPosition
		(glm::vec2(getPosition().x - 10.0f, getPosition().y));
		bullet->activate(true);
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
