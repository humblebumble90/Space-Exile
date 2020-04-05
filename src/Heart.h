/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The header file of heart symbol.
 */
#pragma once
#ifndef __HEART__
#define __HEART__

#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Config.h"

class Heart: public DisplayObject
{
public:
	Heart(std::string imagePath = "../Assets/textures/Slot Machine/heart.png",
		std::string name = "Heart",
		GameObjectType type = HEART,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.25f), bool isCentered = false);
	~Heart();

	
	void draw() override;
	void update() override;
	void clean() override;

private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
	
};
#endif /*Defined (__HEART__)*/

