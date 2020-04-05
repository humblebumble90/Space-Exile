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
	void update() override;
	void clean() override;

	void activate(bool newState);
	bool isActivated();
private:
	void move();
	float m_maxSpeed;
	std::string m_name;
	Uint8 m_alpha;

	bool activated;
};
#endif /*Defined(__LASER__)*/