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
	setVelocity(glm::vec2(1.0f * m_maxSpeed, getVelocity().y));
	std::cout << "Laser instantiated!\n";
}

Laser::~Laser()
{
}

void Laser::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Laser::update()
{
	move();
	if(getPosition().x > Config::SCREEN_WIDTH)
	{
		activate(false);
		std::cout << "Deactivated\n";
	}
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

void Laser::move()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;
	setPosition(glm::vec2(deltax, deltay));
}
