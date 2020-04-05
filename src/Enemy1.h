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

private:
	float m_maxSpeed;
	glm::vec2 startPosition;
	glm::vec2 startVelocity;
	std::string m_name;
	Uint8 m_alpha;
	float m_verticalSwitchCooldown;
	float m_time;

	void move();
	void fire();
	void checkBound();
};
#endif/*Defined (__ENEMY1__)*/