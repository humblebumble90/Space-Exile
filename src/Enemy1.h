/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-05-2020
 * Description: Implement enemy1's feature. This enemy just move to player side.
 */
#pragma once
#include "DisplayObject.h"
#include <SDL_hints.h>
#ifndef __ENEMY1__
#define __ENEMY1__
class Enemy1:public DisplayObject
{
public:

	Enemy1();
	~Enemy1();
	
	void draw() override;
	void update() override;
	void clean() override;

	void setSpawningPosition(glm::vec2 pos);

	void activate(bool newState);
	bool isActivated();
private:
	float m_maxSpeed;
	glm::vec2 startPosition;
	glm::vec2 startVelocity;
	std::string m_name;
	glm::vec2 size;
	Uint8 m_alpha;
	float m_verticalSwitchCooldown;
	float m_time;
	bool m_activated;

	void move();
	void checkBound();
};
#endif/*Defined (__ENEMY1__)*/