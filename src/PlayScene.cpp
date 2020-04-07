#include "PlayScene.h"
#include <SDL.h>
#include "game.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "ScoreBoard.h"
#include "ExplosionManager.h"
#include "ItemManager.h"

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
	ExplosionManager::Instance()->draw();
	ItemManager::Instance()->draw();
}

void PlayScene::spawnEnemy()
{
	m_pEnemy1 = EnemyManager::Instance()->getEnemy1();
	rndYPos = rand() % 161 + 80;
	m_pEnemy1->setSpawningPosition
		(glm::vec2(Config::SCREEN_WIDTH*0.8f, rndYPos));
	m_pEnemy1->activate(true);

	m_pEnemy1 = EnemyManager::Instance()->getEnemy1();
	rndYPos = rand() % 161 + 300;
	m_pEnemy1->setSpawningPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, rndYPos));
	m_pEnemy1->activate(true);

	m_pEnemy1 = EnemyManager::Instance()->getEnemy1();
	rndYPos = rand() % 161 + 520;
	m_pEnemy1->setSpawningPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, rndYPos));
	m_pEnemy1->activate(true);

	m_pEnemy2 = EnemyManager::Instance()->getEnemy2();
	rndYPos = rand() % 340 + 20;
	m_pEnemy2->setPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, rndYPos));
	m_pEnemy2->setTarget(m_pPlayer->getPosition());
	m_pEnemy2->activate(true);

	m_pEnemy2 = EnemyManager::Instance()->getEnemy2();
	rndYPos = rand() % 181 + 400;
	m_pEnemy2->setPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.8f, rndYPos));
		m_pEnemy2->setTarget(m_pPlayer->getPosition());
	m_pEnemy2->activate(true);
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
				if(!m_pPlayer->isProtected())
				{
					displayExplosion(m_pPlayer->getPosition());
				}
				m_pHpLabel
					->setText("Hp: " 
						+ std::to_string(ScoreBoard::Instance()->getHP() * 20)
					+ "%");
				if(m_pPlayer->getPlayerHP() <= 0)
				{
					Game::Instance()->changeSceneState(END_SCENE);
				}
			}
			for(auto laser : BulletManager::Instance()->getBulletPool())
			{
				if(CollisionManager::squaredRadiusCheck(laser,enemy1) &&
					laser->isActivated())
				{
					std::cout << "Enemy 1 is shot by laser!";
					enemy1->activate(false);
					SoundManager::Instance()->playSound("enemyHit", 0);
					laser->activate(false);
					displayExplosion(enemy1->getPosition());
					
					rndint = rand() % 100;
					if(rndint < 5)
					{
						m_pShield = ItemManager::Instance()->getShield();
						m_pShield->setPosition(enemy1->getPosition());
						m_pShield->activate(true);
					}
					
					ScoreBoard::Instance()->setScore(100);
					m_pScoreLabel->setText("Score : "
						+ std::to_string(ScoreBoard::Instance()->getScore()));
					m_pHighscoreLabel
						->setText("HIghscore: " + std::to_string(ScoreBoard::Instance()->getHighScore()));
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
				if (!m_pPlayer->isProtected())
				{
					displayExplosion(m_pPlayer->getPosition());
				}
				m_pHpLabel
					->setText("Hp: "
						+ std::to_string(ScoreBoard::Instance()->getHP() * 20)
						+ "%");
				if (m_pPlayer->getPlayerHP() <= 0)
				{
					Game::Instance()->changeSceneState(END_SCENE);
				}
			}
			for (auto laser : BulletManager::Instance()->getBulletPool())
			{
				if (CollisionManager::squaredRadiusCheck(laser, enemy2) &&
					laser->isActivated())
				{
					std::cout << "Enemy 2 is shot by laser!";
					enemy2 -> activate(false);
					SoundManager::Instance()->playSound("enemyHit", 0);
					laser->activate(false);
					displayExplosion(enemy2->getPosition());
					rndint = rand() % 100;
					if (rndint < 20)
					{
						m_pShield = ItemManager::Instance()->getShield();
						m_pShield->setPosition(enemy2->getPosition());
						m_pShield->activate(true);
					}
					if (rndint > 19 && rndint < 25)
					{
						m_pPowerUp = ItemManager::Instance()->getPowerUp();
						m_pPowerUp->setPosition(enemy2->getPosition());
						m_pPowerUp->activate(true);
					}
					ScoreBoard::Instance()->setScore(200);
					m_pScoreLabel->setText("Score : "
						+ std::to_string(ScoreBoard::Instance()->getScore()));
					m_pHighscoreLabel
						->setText("HIghscore: " + std::to_string(ScoreBoard::Instance()->getHighScore()));
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
						displayExplosion(m_pPlayer->getPosition());
						m_pHpLabel
							->setText("Hp: "
								+ std::to_string(ScoreBoard::Instance()->getHP() * 20)
								+ "%");
						if (m_pPlayer->getPlayerHP() <= 0)
						{
							Game::Instance()->changeSceneState(END_SCENE);
						}
					}
				}
			}
		}
	}
	for (auto shield : ItemManager::Instance()->getShieldPool())
	{
		if (shield->isActivated())
		{
			if (CollisionManager::squaredRadiusCheck(m_pPlayer, shield))
			{
				m_pPlayer->protect(true);
				shield->activate(false);
			}
		}
	}
	for(auto powerUp : ItemManager::Instance()->getPowerUpPool())
	{
		if(powerUp->isActivated())
		{
			if(CollisionManager::squaredRadiusCheck(m_pPlayer,powerUp))
			{
				if(m_pPlayer->getPlayerPowLev() < 2)
				{
					m_pPlayer->setPlayerPowLev(1);
				}
				else
				{
					ScoreBoard::Instance()->setScore(200);
				}
				powerUp->activate(false);
			}
		}
	}
	
}

void PlayScene::displayExplosion(glm::vec2 pos)
{
	m_pExplosion = ExplosionManager::Instance()->getExplosion();
	m_pExplosion->setPosition(pos);
	m_pExplosion->activate();
}

void PlayScene::update()
{
	enemySpawningCooldown++;
	
	m_pMap1->update();
	m_pMap2->update();
	m_pPlayer->update();
	BulletManager::Instance()->update();
	EnemyManager::Instance()->update();
	ExplosionManager::Instance()->update();
	ItemManager::Instance()->update();
	
	if(enemySpawningCooldown >= 150)
	{
		spawnEnemy();
		enemySpawningCooldown = 0;
	}

	checkCollision();


}

void PlayScene::clean()
{
	delete m_pMap1;
	delete m_pMap2;
	delete m_pScoreLabel;
	delete m_pHpLabel;
	delete m_pHighscoreLabel;
	delete m_pPlayer;
	delete m_pEnemy1;
	delete m_pEnemy2;
	delete m_pShield;
	delete m_pPowerUp;
	delete m_pExplosion;
	TheSoundManager::Instance()->clear();
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	m_pKeyStates = SDL_GetKeyboardState(NULL);
	
	if (m_pKeyStates[SDL_SCANCODE_LEFT] || m_pKeyStates[SDL_SCANCODE_A])
	{
		m_pPlayer->move(LEFT);
	}
	if (m_pKeyStates[SDL_SCANCODE_RIGHT] || m_pKeyStates[SDL_SCANCODE_D])
	{
		m_pPlayer->move(RIGHT);
	}
	if (m_pKeyStates[SDL_SCANCODE_UP] || m_pKeyStates[SDL_SCANCODE_W])
	{
		m_pPlayer->move(UP);
	}
	if (m_pKeyStates[SDL_SCANCODE_DOWN] || m_pKeyStates[SDL_SCANCODE_S])
	{
		m_pPlayer->move(DOWN);
	}
	if(m_pKeyStates[SDL_SCANCODE_ESCAPE])
	{
		Game::Instance()->quit();
	}
	if(m_pKeyStates[SDL_SCANCODE_SPACE] ||
		SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		m_pPlayer->fire();
	}
	if(m_pKeyStates[SDL_SCANCODE_KP_PLUS])
	{
		m_pPlayer->setPlayerPowLev(1);
	}
	if(m_pKeyStates[SDL_SCANCODE_KP_MINUS])
	{
		m_pPlayer->setPlayerPowLev(-1);
	}
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		//case SDL_KEYDOWN:
		//	switch(event.key.keysym.sym)
		//	{
		//	case SDLK_KP_PLUS:
		//		m_pPlayer->setPlayerPowLev(1);
		//		break;
		//	case SDLK_KP_MINUS:
		//		m_pPlayer->setPlayerPowLev(-1);
		//		break;
		//	default:
		//		break;
		//	}
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

void PlayScene::initializePooling()
{
	EnemyManager::Instance()->buildEnemy1Pool();
	EnemyManager::Instance()->buildEnemy2Pool();
	BulletManager::Instance()->m_buildLaserPool();
	BulletManager::Instance()->m_buildEnemyLaserPool();
	ExplosionManager::Instance()->m_buildExplosionPool();
	ItemManager::Instance()->buildShieldPool();
	ItemManager::Instance()->buildPowerUpPool();
}

void PlayScene::start()
{
	initializePooling();
	ScoreBoard::Instance()->resetValues();
	enemySpawningCooldown = 0;
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
	("HP: " + std::to_string(ScoreBoard::Instance()->getHP() * 20)
		+ "%",
		"QuirkyRobot", 60, color,
		glm::vec2(Config::SCREEN_WIDTH * 0.90f, Config::SCREEN_HEIGHT * 0.05f));
	m_pHpLabel->setParent(this);
	addChild(m_pHpLabel);

	m_pScoreLabel = new Label
	("Score: " + std::to_string(ScoreBoard::Instance()->getScore()),
		"QuirkyRobot",60,color,
		glm::vec2(Config::SCREEN_WIDTH * 0.90f, Config::SCREEN_HEIGHT*0.15f));
	m_pScoreLabel->setParent(this);
	addChild(m_pScoreLabel);


	m_pHighscoreLabel = new Label
	("Highscore: " + std::to_string(ScoreBoard::Instance()->getHighScore()),
		"QuirkyRobot", 60, color,
		glm::vec2(Config::SCREEN_WIDTH * 0.85f, Config::SCREEN_HEIGHT * 0.25f));
	m_pScoreLabel->setParent(this);
	addChild(m_pHighscoreLabel);
	
	m_pPlayer = new Player();
	m_pPlayer->setParent(this);
	addChild(m_pPlayer);

	SoundManager::Instance()->load("../Assets/audio/playScene_theme.ogg",
		"playScene_theme", SOUND_MUSIC);
	SoundManager::Instance()->playMusic("playScene_theme", 999);
	SoundManager::Instance()
		->load("../Assets/audio/laser.wav", "fire", SOUND_SFX);
	SoundManager::Instance()
		->load("../Assets/audio/hit.wav", "hit", SOUND_SFX);
	SoundManager::Instance()
		->load("../Assets/audio/enemyLaser.wav", "enemyLaser", SOUND_SFX);
	SoundManager::Instance()
		->load("../Assets/audio/enemyHit.wav", "enemyHit", SOUND_SFX);
}
