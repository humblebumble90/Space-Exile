/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Explosion manager built in object pooling way.
 */
#pragma once
#ifndef __EXPLOSION_MANAGER__
#define __EXPLOSION_MANAGER__
#include <list>
#include "Explosion.h"
#endif

class ExplosionManager
{
public:
	static ExplosionManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new ExplosionManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void clean();
	void m_buildExplosionPool();
	Explosion* getExplosion();
	void update();
	void draw();
private:
	ExplosionManager();
	~ExplosionManager();



	int m_explosionNumber;
	static ExplosionManager* s_pInstance;

	std::list<Explosion*> m_pExplosionPool;
};