/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-05-2020
 * Description: The header file of the play-scene that main game is displayed.
 */
#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__
#include "Scene.h"
#include "Map.h"
#include "Player.h"
#include "Enemy1.h"
#include <list>
#include "Label.h"
#include "Enemy2.h"
#include "Shield.h"
#include "PowerUp.h"
#include "Explosion.h"


class PlayScene:public Scene
{
public:
	PlayScene();
	~PlayScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void initializePooling();
	void start() override;
private:
	Map* m_pMap1;
	Map* m_pMap2;
	Label* m_pHpLabel;
	Label* m_pScoreLabel;
	Label* m_pHighscoreLabel;
	Player* m_pPlayer;

	Enemy1* m_pEnemy1;
	Enemy2* m_pEnemy2;
	Shield* m_pShield;
	PowerUp* m_pPowerUp;
	Explosion* m_pExplosion;

	const Uint8* m_pKeyStates;
	int enemySpawningCooldown;
	int rndint;
	int rndYPos;
	
	void spawnEnemy();
	void checkCollision();
	void displayExplosion(glm::vec2 pos);

};
#endif /*Defined __PLAY_SCENE__*/

