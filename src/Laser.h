/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-05-2020
 * Description: Implement a laser's features. Enemy can also use laser
 * after switch laser to enemy laser by implementing switchToEnemyLaser method.
 */
#pragma once
#include "DisplayObject.h"
#include "Config.h"
#include <SDL_hints.h>
#ifndef __LASER__
#define __LASER__
class Laser :public DisplayObject
{
public:
	Laser();
	~Laser();
	
	void draw() override;
	void checkBound();
	void update() override;
	void clean() override;

	void activate(bool newState);
	bool isActivated();

	void switchToEnemyLaser();

	float getMaxSpeed();
private:
	void move();
	float m_maxSpeed;
	std::string m_name;
	Uint8 m_alpha;
	bool activated;
	float m_angle;
};
#endif /*Defined(__LASER__)*/