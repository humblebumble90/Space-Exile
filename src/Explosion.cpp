#include "explosion.h"
#include "Game.h"

Explosion::Explosion() :m_currentFrame(0), m_currentRow(0), m_bisActive(false)
{
	TextureManager::Instance()->load("../Assets/textures/explosion.png",
	"explosion",Game::Instance()->getRenderer());
	auto size = TheTextureManager::Instance()->getTextureSize("explosion");
	setWidth(size.x);
	setHeight(size.y);

	setPosition(glm::vec2(400.0f, 300.0f));
	setIsColliding(false);
	setType(EXPLOSION);
}
Explosion::~Explosion()
= default;
void Explosion::draw()
{
	const int xComponent = getPosition().x;
	const int yComponent = getPosition().y;

	if (m_currentRow < 3)
	{
		TheTextureManager::Instance()->drawFrame("explosion", xComponent,
			yComponent, getWidth()/4, getHeight()/4, m_currentRow,
			m_currentFrame, TheGame::Instance()->getRenderer(),
			4, 4, 1.0f,
			TheGame::Instance()->getRenderer(), 180, 255, true);
	}
	else
	{
		activate(false);
	}
}

void Explosion::update()
{
}

void Explosion::clean()
{

}

void Explosion::activate()
{
	m_currentFrame = 0;
	m_currentRow = 0;
	m_bisActive = true;
}

void Explosion::activate(bool newState)
{
	m_bisActive = newState;
	if(m_bisActive = false)
	{
		setPosition(glm::vec2(-1000.0f, -1000.0f));
		m_bisActive = false;
	}
}

bool Explosion::getIsActive()
{
	return m_bisActive;
}