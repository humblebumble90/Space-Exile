#include "BulletManager.h"

BulletManager* BulletManager::s_pInstance = nullptr;

BulletManager::BulletManager() :m_LaserNumber(10),m_enemyLaserNumber(10)
{
	m_buildLaserPool();
	m_buildEnemyLaserPool();
}

BulletManager::~BulletManager()
= default;

void BulletManager::clean()
{
}

Laser* BulletManager::getBullet()
{
	Laser* laser = m_pLaserPool.front();
	m_pLaserPool.pop_front();
	m_pLaserPool.push_back(laser);
	return laser;
}

Laser* BulletManager::getEnemyBullet()
{
	Laser* laser = m_pEnemyLaserPool.front();
	m_pEnemyLaserPool.pop_front();
	m_pEnemyLaserPool.push_back(laser);
	return laser;
}

std::list<Laser*> BulletManager::getBulletPool()
{
	return m_pLaserPool;
}

std::list<Laser*> BulletManager::getEnemyBulletPool()
{
	return m_pEnemyLaserPool;
}

void BulletManager::update()
{
	for(auto laser : m_pLaserPool)
	{
		if(laser->isActivated())
		{
			laser->update();
		}
	}
	for (auto laser : m_pEnemyLaserPool)
	{
		if (laser->isActivated())
		{
			laser->update();
		}
	}
}

void BulletManager::draw()
{
	for (auto laser : m_pLaserPool)
	{
		if(laser->isActivated())
		{
			laser->draw();
		}
	}
	for (auto laser : m_pEnemyLaserPool)
	{
		if (laser->isActivated())
		{
			laser->draw();
		}
	}
}

void BulletManager::m_buildLaserPool()
{
	m_pLaserPool = std::list<Laser*>();

	for (int i = 0; i < m_LaserNumber; i++)
	{
		m_pLaserPool.push_back(new Laser());
	}
}

void BulletManager::m_buildEnemyLaserPool()
{
	m_pEnemyLaserPool = std::list<Laser*>();

	for (int i = 0; i < m_enemyLaserNumber; i++)
	{
		m_pEnemyLaserPool.push_back(new Laser());
	}
}
