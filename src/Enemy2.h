#pragma once
#include "DisplayObject.h"
#include <SDL_hints.h>
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
private:
	float m_maxSpeed;
	glm::vec2 startPosition;
	glm::vec2 startVelocity;
	std::string m_name;
	Uint8 m_alpha;
	
	float m_coolTime;
	float m_fireRate;
	bool m_activated;

	void move();
	void fire();
	void checkBound();
};
#endif/*Defined (__ENEMY2__)*/