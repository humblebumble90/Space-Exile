/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Explosion animation when the player or enemies are hit.
 */
#include "DisplayObject.h"
#pragma once
#ifndef __EXPLOSION__
#define __EXPLOSION__
class Explosion : public DisplayObject
{
public:
	Explosion();
	~Explosion();

	void draw() override;
	void update() override;
	void clean() override;
	void activate();
	void activate(bool newState);
	bool Explosion::getIsActive();
private:
	int m_currentFrame;
	int m_currentRow;
	bool m_bisActive;
};
#endif/*Defined (__EXPLOSION__)*/