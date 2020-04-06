/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Bullet manager built in object pooling way.
 */
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
	void m_buildLaserPool();
	void m_buildEnemyLaserPool();
private:
	BulletManager();
	~BulletManager();

	int m_LaserNumber;
	int m_enemyLaserNumber;

	static BulletManager* s_pInstance;

	std::list<Laser*> m_pLaserPool;
	std::list<Laser*> m_pEnemyLaserPool;
};