/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Myself
 * StudentNumber: 301011097
 * Written date : 04-05-2020
 * Description: Implement playscene background img loading and scrolling
 */
#pragma once
#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Config.h"
#ifndef __MAP__
#define __MAP__
class Map :public DisplayObject
{
public:
	Map(std::string imagePath = "../Assets/textures/playScene_bg.png",
		std::string name = "playScene_bg",
		GameObjectType type = PLAY_SCENE_BG,
		glm::vec2 position =
		glm::vec2(0.0f,0.0f));
	~Map();
	void draw() override;
	void update() override;
	void clean() override;
private:
	void move();
	void reset();
	
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
	
};
#endif /*Defined (__MAP__)*/