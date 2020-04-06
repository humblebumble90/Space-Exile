/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Shield item.
 */
#pragma once
#include "DisplayObject.h"
#ifndef __SHIELD__
#define __SHIELD__
class Shield :public DisplayObject
{
public:
	Shield();
	~Shield();
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