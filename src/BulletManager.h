#pragma once
#ifndef __BULLET_MANAGER__
#define __BULLET_MANAGER__
#include <list>
#include "Laser.h"
#endif/*Defined(__BULLET_MANAGER__)*/

class BulletManager
{
public:
	static BulletManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new BulletManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void clean();

	Laser* getBullet();
	Laser* getEnemyBullet();
	
	std::list<Laser*> getBulletPool();
	std::list<Laser*> getEnemyBulletPool();
	
	void update();
	void draw();
private:
	BulletManager();
	~BulletManager();

	int m_LaserNumber;
	int m_enemyLaserNumber;
	
	void m_buildLaserPool();
	void m_buildEnemyLaserPool();
	static BulletManager* s_pInstance;

	std::list<Laser*> m_pLaserPool;
	std::list<Laser*> m_pEnemyLaserPool;
};