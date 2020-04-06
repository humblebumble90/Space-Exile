#include "Shield.h"
#include "TextureManager.h"
#include "Game.h"

Shield::Shield():m_Activated(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/Shield.png",
		"shield", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("shield");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(-5.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::SHIELD);
}

Shield::~Shield()
= default;

void Shield::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("shield", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void Shield::move()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;
	setPosition(glm::vec2(deltax, deltay));
}

void Shield::checkBound()
{
	if (getPosition().x > Config::SCREEN_WIDTH || getPosition().x < 0 ||
		getPosition().y > Config::SCREEN_HEIGHT || getPosition().y < 0)
	{
		activate(false);
		std::cout << "Deactivated\n";
	}
}

void Shield::update()
{
	move();
	checkBound();
	
}

void Shield::clean()
{
}

void Shield::activate(bool newState)
{
	m_Activated = newState;
}

bool Shield::isActivated()
{
	return m_Activated;
}
