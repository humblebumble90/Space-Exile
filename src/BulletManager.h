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
	void update();
	void draw();
private:
	BulletManager();
	~BulletManager();

	int m_LaserNumber;
	void m_buildLaserPool();
	static BulletManager* s_pInstance;

	std::list<Laser*> m_pLaserPool;
};