#include "Map.h"
#include "TextureManager.h"
#include "Game.h"

Map::Map(std::string imagePath, std::string name,
         GameObjectType type, glm::vec2 position)
	: m_name(name), m_alpha(255)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setType(type);
	setVelocity(glm::vec2(5.0f, 0.0f));
	std::cout << "background instantiated!\n";
}

Map::~Map()
= default;

void Map::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, false);
}

void Map::update()
{
	move();
	reset();
}

void Map::clean()
{
}

void Map::move()
{
	glm::vec2 newPosition = getPosition() + getVelocity();
	setPosition(newPosition);
}

void Map::reset()
{
	if (getPosition().x >= 1280.0f)
	{
		setPosition(glm::vec2(-1280.0f, 0.0f));
	}
}
