#pragma once
#ifndef __ENEMY1_MANAGER__
#define __ENEMY1_MANAGER__
#include <list>
#include "Enemy1.h"
#include "Enemy2.h"
#endif/*Defined(__ENEMY1_MANAGER__)*/

class EnemyManager
{
public:
	static EnemyManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new EnemyManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void clean();

	Enemy1* getEnemy1();
	Enemy2* getEnemy2();
	
	std::list<Enemy1*> getENemy1Pool();
	std::list<Enemy2*> getEnemy2Pool();
	
	void update();
	void draw();
private:
	EnemyManager();
	~EnemyManager();

	int m_Enemy1Number;
	int m_Enemy2Number;
	
	void buildEnemy1Pool();
	void buildEnemy2Pool();
	static EnemyManager* s_pInstance;

	std::list<Enemy1*> m_pEnemy1Pool;
	std::list<Enemy2*> m_pEnemy2Pool;
};