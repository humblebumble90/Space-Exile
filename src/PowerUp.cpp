#include "PowerUp.h"
#include "TextureManager.h"
#include "Game.h"

PowerUp::PowerUp() :m_Activated(false)
{
	TheTextureManager::Instance()->load("../Assets/textures/powerup.png",
		"powerup", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("powerup");
	setWidth(size.x);
	setHeight(size.y);
	setVelocity(glm::vec2(-5.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::SHIELD);
}

PowerUp::~PowerUp()
= default;

void PowerUp::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw("powerup", xComponent, yComponent,
		TheGame::Instance()->getRenderer());
}

void PowerUp::move()
{
	auto currentPosition = getPosition();
	auto currentVelocity = getVelocity();

	setVelocity(glm::vec2(currentVelocity.x, currentVelocity.y));
	auto deltax = currentPosition.x + currentVelocity.x;
	auto deltay = currentPosition.y + currentVelocity.y;
	setPosition(glm::vec2(deltax, deltay));
}

void PowerUp::checkBound()
{
	if (getPosition().x > Config::SCREEN_WIDTH || getPosition().x < 0 ||
		getPosition().y > Config::SCREEN_HEIGHT || getPosition().y < 0)
	{
		activate(false);
		std::cout << "Deactivated\n";
	}
}

void PowerUp::update()
{
	move();
	checkBound();

}

void PowerUp::clean()
{
}

void PowerUp::activate(bool newState)
{
	m_Activated = newState;
}

bool PowerUp::isActivated()
{
	return m_Activated;
}
