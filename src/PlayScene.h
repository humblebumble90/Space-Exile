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


class PlayScene:public Scene
{
public:
	PlayScene();
	~PlayScene();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
private:
	Map* m_pMap1;
	Map* m_pMap2;
	Label* m_pHpLabel;
	Label* m_pScoreLabel;
	Label* m_pHighscoreLabel;
	Player* m_pPlayer;
	int enemy1SpawningCooldown;
	
	void spawnEnemy();
	void checkCollision();

};
#endif /*Defined __PLAY_SCENE__*/

