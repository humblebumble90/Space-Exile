#include "Laser.h"
#include "TextureManager.h"
#include "game.h"

Laser::Laser()
	:m_name("laser"),m_alpha(255),m_maxSpeed(10.0f), activated(false)
{
	std::string imagePath = "../Assets/textures/laser_player.png";
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setType(PLAYER_LASER);
	setVelocity(glm::vec2(1.0f * m_maxSpeed, 0.0f));
	std::cout << "Laser instantiated!\n";

}

Laser::~Laser()
{
}

void Laser::draw()
{
		int xComponent = getPosition().x;
		int yComponent = getPosition().y;
	//	m_angle = 180.0f/  glm::pi<float>()
	//* getVelocity().y / (getVelocity().x + glm::abs(getVelocity().y));
		m_angle = glm::degrees(std::atan2(getVelocity().y, getVelocity().x));
		TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
			TheGame::Instance()->getRenderer(), m_angle, m_alpha, true);
}

void Laser::checkBound()
{
	if(getPosition().x > Config::SCREEN_WIDTH || 	getPosition().x < 0 ||
		getPosition().y > Config::SCREEN_HEIGHT || getPosition().y < 0)
	{
		activate(false);
		std::cout << "Deactivated\n";
	}
}

void Laser::update()
{
	move();
	checkBound();
}

void Laser::clean()
{
}

void Laser::activate(bool newState)
{
	activated = newState;
}

bool Laser::isActivated()
{
	return activated;
}

void Laser::switchToEnemyLaser()
{
	m_name = "enemyLaser";
	std::string imagePath = "../Assets/textures/laser_enemy.png";
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());
	setType(ENEMY);
}

float Laser::getMaxSpeed()
{
	return m_maxSpeed;
}

void Laser::move()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;
	setPosition(glm::vec2(deltax, deltay));
}
