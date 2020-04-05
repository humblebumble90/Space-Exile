#pragma once
#ifndef __ENEMY1_MANAGER__
#define __ENEMY1_MANAGER__
#include <list>
#include "Enemy1.h"
#endif/*Defined(__ENEMY1_MANAGER__)*/

class Enemy1Manager
{
public:
	static Enemy1Manager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new Enemy1Manager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void clean();

	Enemy1* getEnemy1();
	void update();
	void draw();
private:
	Enemy1Manager();
	~Enemy1Manager();

	int m_Enemy1Number;
	void m_buildEnemy1Pool();
	static Enemy1Manager* s_pInstance;

	std::list<Enemy1*> m_pEnemy1Pool;
};