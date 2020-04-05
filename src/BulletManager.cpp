#include "BulletManager.h"

BulletManager* BulletManager::s_pInstance = nullptr;

BulletManager::BulletManager() :m_LaserNumber(10)
{
	m_buildLaserPool();
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

void BulletManager::update()
{
	for(auto laser : m_pLaserPool)
	{
		if(laser->isActivated())
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
}

void BulletManager::m_buildLaserPool()
{
	m_pLaserPool = std::list<Laser*>();

	for (int i = 0; i < m_LaserNumber; i++)
	{
		m_pLaserPool.push_back(new Laser());
	}
}
