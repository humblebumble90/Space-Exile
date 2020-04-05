#include "PlayScene.h"
#include <SDL.h>
#include "game.h"
#include "BulletManager.h"
#include "Enemy1Manager.h"

PlayScene::PlayScene()
{
	start();
}

PlayScene::~PlayScene()
{
}

void PlayScene::draw()
{
	m_pMap1->draw();
	m_pMap2->draw();
	m_pPlayer->draw();
	BulletManager::Instance()->draw();
	Enemy1Manager::Instance()->draw();
}

void PlayScene::spawnEnemy1()
{
	auto enemy1_1 = Enemy1Manager::Instance()->getEnemy1();
	int randNum_1 = rand() % 201 + 20;
	enemy1_1->setSpawningPosition
		(glm::vec2(Config::SCREEN_WIDTH*0.9f, randNum_1));
	enemy1_1->activate(true);

	auto enemy1_2 = Enemy1Manager::Instance()->getEnemy1();
	int randNum_2 = rand() % 221 + 200;
	enemy1_2->setSpawningPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.9f, randNum_2));
	enemy1_2->activate(true);

	auto enemy1_3 = Enemy1Manager::Instance()->getEnemy1();
	int randNum_3 = rand() % 241 + 400;
	enemy1_3->setSpawningPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.9f, randNum_3));
	enemy1_3->activate(true);
}

void PlayScene::update()
{
	enemy1SpawningCooldown++;
	m_pMap1->update();
	m_pMap2->update();
	m_pPlayer->update();
	BulletManager::Instance()->update();
	Enemy1Manager::Instance()->update();
	if(enemy1SpawningCooldown > 300)
	{
		spawnEnemy1();
		enemy1SpawningCooldown = 0;
	}
}

void PlayScene::clean()
{
}

void PlayScene::handleEvents()
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	
	if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
	{
		m_pPlayer->move(LEFT);
	}
	if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
	{
		m_pPlayer->move(RIGHT);
	}
	if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
	{
		m_pPlayer->move(UP);
	}
	if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
	{
		m_pPlayer->move(DOWN);
	}
	if(keystates[SDL_SCANCODE_ESCAPE])
	{
		Game::Instance()->quit();
	}
	if(keystates[SDL_SCANCODE_SPACE] ||
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		m_pPlayer->fire();
	}
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				m_pPlayer->setVelocity(glm::vec2(m_pPlayer->getVelocity().x, 0.0f));
				break;
			case SDLK_a:
				m_pPlayer->setVelocity(glm::vec2( 0.0f,m_pPlayer->getVelocity().y));
				break;
			case SDLK_s:
				m_pPlayer->setVelocity(glm::vec2(m_pPlayer->getVelocity().x, 0.0f));
				break;
			case SDLK_d:
				m_pPlayer->setVelocity(glm::vec2(0.0f, m_pPlayer->getVelocity().y));
				break;
			case SDLK_UP:
				m_pPlayer->setVelocity(glm::vec2(m_pPlayer->getVelocity().x, 0.0f));
				break;
			case SDLK_LEFT:
				m_pPlayer->setVelocity(glm::vec2(0.0f, m_pPlayer->getVelocity().y));
				break;
			case SDLK_DOWN:
				m_pPlayer->setVelocity(glm::vec2(m_pPlayer->getVelocity().x, 0.0f));
				break;
			case SDLK_RIGHT:
				m_pPlayer->setVelocity(glm::vec2(0.0f, m_pPlayer->getVelocity().y));
				break;
			default:
				break;
			}
		}
	}
}

void PlayScene::start()
{
	enemy1SpawningCooldown = 0;
	m_pMap1 = new Map();
	m_pMap1->setPosition(glm::vec2(-1280.0f,0.0f));
	m_pMap1->setParent(this);
	addChild(m_pMap1);
	m_pMap2 = new Map();
	m_pMap2->setPosition(glm::vec2(0.0f, 0.0f));
	m_pMap2->setParent(this);
	addChild(m_pMap2);
	m_pPlayer = new Player();
	m_pPlayer->setParent(this);
	addChild(m_pPlayer);

	//m_pEnemy1 = new Enemy1();
	//m_pEnemy1->setSpawningPosition(
	//	glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.5f));
	//m_pEnemy1->setParent(this);
	//addChild(m_pEnemy1);
}
