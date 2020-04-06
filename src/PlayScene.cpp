#include "PlayScene.h"
#include <SDL.h>
#include "game.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "ScoreBoard.h"

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
	m_pScoreLabel->draw();
	m_pHpLabel->draw();
	m_pHighscoreLabel->draw();
	m_pPlayer->draw();
	BulletManager::Instance()->draw();
	EnemyManager::Instance()->draw();
}

void PlayScene::spawnEnemy()
{
	auto enemy1_1 = EnemyManager::Instance()->getEnemy1();
	int randNum_1 = rand() % 161 + 80;
	enemy1_1->setSpawningPosition
		(glm::vec2(Config::SCREEN_WIDTH*0.8f, randNum_1));
	enemy1_1->activate(true);

	auto enemy1_2 = EnemyManager::Instance()->getEnemy1();
	int randNum_2 = rand() % 161 + 300;
	enemy1_2->setSpawningPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, randNum_2));
	enemy1_2->activate(true);

	auto enemy1_3 = EnemyManager::Instance()->getEnemy1();
	int randNum_3 = rand() % 161 + 520;
	enemy1_3->setSpawningPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, randNum_3));
	enemy1_3->activate(true);

	auto enemy2 = EnemyManager::Instance()->getEnemy2();
	int randNum_4 = rand() % 560 + 20;
	enemy2->setPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, randNum_4));
	enemy2->activate(true);
}

void PlayScene::checkCollision()
{
	for(auto enemy1 : EnemyManager::Instance()->getENemy1Pool())
	{
		if(enemy1->isActivated())
		{
			if (CollisionManager::squaredRadiusCheck(m_pPlayer, enemy1) &&
				!m_pPlayer->getInvincible())
			{
				std::cout << "Collision with enemy1\n";
				m_pPlayer->hit();
				m_pHpLabel
					->setText("Hp: " 
						+ std::to_string(Scoreboard::Instance()->getHP() * 20)
					+ "%");
				if(m_pPlayer->getPlayerHP() <= 0)
				{
					
				}
			}
			for(auto laser : BulletManager::Instance()->getBulletPool())
			{
				if(CollisionManager::squaredRadiusCheck(laser,enemy1) &&
					laser->isActivated())
				{
					std::cout << "Enemy 1 is shot by laser!";
					enemy1->activate(false);
					laser->activate(false);
					Scoreboard::Instance()->setScore(100);
					m_pScoreLabel->setText("Score : "
						+ std::to_string(Scoreboard::Instance()->getScore()));
					m_pHighscoreLabel
						->setText("HIghscore" + Scoreboard::Instance()->getHighScore());
				}
			}
		}
	}

	for(auto enemy2 : EnemyManager::Instance()->getEnemy2Pool())
	{
		if(enemy2->isActivated())
		{
			if(CollisionManager::squaredRadiusCheck(m_pPlayer,enemy2) &&
				!m_pPlayer->getInvincible())
			{
				std::cout << "Collision with enemy2\n";
				m_pPlayer->hit();
				m_pHpLabel
					->setText("Hp: "
						+ std::to_string(Scoreboard::Instance()->getHP() * 20)
						+ "%");
				if (m_pPlayer->getPlayerHP() <= 0)
				{

				}
			}
			for (auto laser : BulletManager::Instance()->getBulletPool())
			{
				if (CollisionManager::squaredRadiusCheck(laser, enemy2) &&
					laser->isActivated())
				{
					std::cout << "Enemy 2 is shot by laser!";
					enemy2 -> activate(false);
					laser->activate(false);
					Scoreboard::Instance()->setScore(200);
					m_pScoreLabel->setText("Score : "
						+ std::to_string(Scoreboard::Instance()->getScore()));
					m_pHighscoreLabel
						->setText("HIghscore" + Scoreboard::Instance()->getHighScore());
				}
			}
			for(auto enemyLaser : BulletManager::Instance()->getEnemyBulletPool())
			{
				if(enemyLaser->isActivated())
				{
					if(CollisionManager::squaredRadiusCheck(m_pPlayer,enemyLaser) &&
						!m_pPlayer->getInvincible())
					{
						std::cout << "Player is shot by enemy laser!\n";
						enemyLaser->activate(false);
						m_pPlayer->hit();
						m_pHpLabel
							->setText("Hp: "
								+ std::to_string(Scoreboard::Instance()->getHP() * 20)
								+ "%");
						if (m_pPlayer->getPlayerHP() <= 0)
						{

						}
					}
				}
			}
		}
	}
	
}

void PlayScene::update()
{
	enemy1SpawningCooldown++;
	
	m_pMap1->update();
	m_pMap2->update();
	m_pPlayer->update();
	BulletManager::Instance()->update();
	EnemyManager::Instance()->update();
	
	if(enemy1SpawningCooldown >= 300)
	{
		spawnEnemy();
		enemy1SpawningCooldown = 0;
	}

	checkCollision();


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

	SDL_Color color = { 255, 200,200, 255 };

	m_pHpLabel = new Label
	("HP: " + std::to_string(Scoreboard::Instance()->getHP() * 20)
		+ "%",
		"QuirkyRobot", 60, color,
		glm::vec2(Config::SCREEN_WIDTH * 0.90f, Config::SCREEN_HEIGHT * 0.05f));
	m_pHpLabel->setParent(this);
	addChild(m_pHpLabel);

	m_pScoreLabel = new Label
	("Score: " + std::to_string(Scoreboard::Instance()->getScore()),
		"QuirkyRobot",60,color,
		glm::vec2(Config::SCREEN_WIDTH * 0.90f, Config::SCREEN_HEIGHT*0.15f));
	m_pScoreLabel->setParent(this);
	addChild(m_pScoreLabel);

	m_pScoreLabel = new Label
	("Score: " + std::to_string(Scoreboard::Instance()->getScore()),
		"QuirkyRobot", 60, color,
		glm::vec2(Config::SCREEN_WIDTH * 0.90f, Config::SCREEN_HEIGHT * 0.15f));
	m_pScoreLabel->setParent(this);
	addChild(m_pScoreLabel);

	m_pHighscoreLabel = new Label
	("Highscore: " + std::to_string(Scoreboard::Instance()->getHighScore()),
		"QuirkyRobot", 60, color,
		glm::vec2(Config::SCREEN_WIDTH * 0.90f, Config::SCREEN_HEIGHT * 0.25f));
	m_pScoreLabel->setParent(this);
	addChild(m_pScoreLabel);
	
	m_pPlayer = new Player();
	m_pPlayer->setParent(this);
	addChild(m_pPlayer);

	//m_pEnemy1 = new Enemy1();
	//m_pEnemy1->setSpawningPosition(
	//	glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.5f));
	//m_pEnemy1->setParent(this);
	//addChild(m_pEnemy1);
}
