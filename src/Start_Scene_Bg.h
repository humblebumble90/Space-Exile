/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The header file of the start scene's background.
 */
#pragma once
#ifndef __START_SCENE_BG__
#define __START_SCENE_BG__
#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Config.h"

class Start_Scene_Bg :public DisplayObject
{
public:
	Start_Scene_Bg(std::string imagePath = "../Assets/textures/startScene_bg.png",
		std::string name = "start_Scene_bg",
		GameObjectType type = START_SCENE_BG,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f), bool isCentered = true);
	~Start_Scene_Bg();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
	
};
#endif /*Defined(__START_SCENE_BG__)*/