/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Instruction image file
 */
#include "DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>
#pragma once
#ifndef __INSTRUCTION__
#define __INSTRUCTION__
class Instruction:public DisplayObject
{
public:
	Instruction(std::string imagePath = "../Assets/textures/instruction.png",
		std::string name = "instruction",
		GameObjectType type = INSTRUCTION,
		glm::vec2 position = glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f), bool isCentered = true);
	~Instruction();
	void draw() override;
	void update() override;
	void clean() override;
private:
	std::string m_name;
	Uint8 m_alpha;
	bool m_isCentered;
};
#endif/*Defined(__INSTRUCTION__)*/