/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-05-2020
 * Description: Implement enemy2's feature. This enemy moves to player side and host laser.
 */
#pragma once
#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Laser.h"
#ifndef __ENEMY2__
#define __ENEMY2__
class Enemy2 :public DisplayObject
{
public:

	Enemy2();
	~Enemy2();

	void draw() override;
	void update() override;
	void clean() override;

	void activate(bool newState);
	bool isActivated();
	void setTarget(glm::vec2 target);
private:
	float m_maxSpeed;
	glm::vec2 startPosition;
	glm::vec2 startVelocity;
	std::string m_name;
	Uint8 m_alpha;
	
	Laser* m_pLaser;
	float m_coolTime;
	float m_fireRate;
	bool m_activated;
	glm::vec2 m_target;
	glm::vec2 m_laserSpeed;

	void move();
	void fire();
	void checkBound();
};
#endif/*Defined (__ENEMY2__)*/