/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Power-up item.
 */
#pragma once
#include "DisplayObject.h"
#ifndef __POWER_UP__
#define __POWER_UP__
class PowerUp :public DisplayObject
{
public:
	PowerUp();
	~PowerUp();
	void draw() override;
	void move();
	void checkBound();
	void update() override;
	void clean() override;
	void activate(bool newState);
	bool isActivated();

private:
	bool collided;
	bool m_Activated;
};
#endif  /*Defined (__SHIELD__)*/