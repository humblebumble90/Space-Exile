#include "Enemy1.h"
#include "TextureManager.h"
#include "game.h"

Enemy1::Enemy1():m_maxSpeed(2.5f),m_name("enemy1"),m_alpha(255),
m_verticalSwitchCooldown(30.0f),m_time(-30.0f)
{
		std::string imagePath = "../Assets/textures/enemy1.png";
		TheTextureManager::Instance()->load(imagePath,
			m_name, TheGame::Instance()->getRenderer());

		glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
		setWidth(size.x);
		setHeight(size.y);
		setType(PLAYER_LASER);
		setVelocity(glm::vec2(-1.0f * m_maxSpeed, -1.0f * m_maxSpeed));
		std::cout << "Enemy1 instantiated!\n";
}

	Enemy1::~Enemy1()
		= default;

void Enemy1::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Enemy1::update()
{
	move();
	checkBound();
}

void Enemy1::clean()
{
}

void Enemy1::setSpawningPosition(glm::vec2 pos)
{
	setPosition(pos);
	startPosition = pos;
	startVelocity = getVelocity();
	std::cout << "Start y pos: "<<startPosition.y << std::endl;
}

void Enemy1::move()
{
	m_time++;
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	if (m_time > 0)
	{
		setVelocity(glm::vec2(getVelocity().x, -startVelocity.y));
	}
	else
	{
		setVelocity(glm::vec2(getVelocity().x, startVelocity.y));
	}
	if (m_time > m_verticalSwitchCooldown)
	{
		m_time = -m_verticalSwitchCooldown;
	}
	
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;

	setPosition(glm::vec2(deltax, deltay));
}

void Enemy1::fire()
{
}

void Enemy1::checkBound()
{
	if (getPosition().x <= Config::SCREEN_WIDTH * 0.03f - getWidth())
	{
		setSpawningPosition(startPosition);
	}
	if (getPosition().y <= Config::SCREEN_HEIGHT * 0.03f - getHeight())
	{
		setSpawningPosition(startPosition);
	}
	if (getPosition().y >= Config::SCREEN_HEIGHT * 0.97f + getHeight())
	{
		setSpawningPosition(startPosition);
	}
}
