/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The header file of the play-scene that main game is displayed.
 */
#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__
#include "Scene.h"
#include "Map.h"


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
};
#endif /*Defined __PLAY_SCENE__*/

