#include "EnemyManager.h"

EnemyManager* EnemyManager::s_pInstance = nullptr;

EnemyManager::EnemyManager():m_Enemy1Number(10),m_Enemy2Number(10)
{
	buildEnemy1Pool();
	buildEnemy2Pool();
}

EnemyManager::~EnemyManager()
= default;

void EnemyManager::clean()
{
}

Enemy1* EnemyManager::getEnemy1()
{
	Enemy1* enemy1 = m_pEnemy1Pool.front();
	m_pEnemy1Pool.pop_front();
	m_pEnemy1Pool.push_back(enemy1);
	return enemy1;
}

Enemy2* EnemyManager::getEnemy2()
{
	Enemy2* enemy2 = m_pEnemy2Pool.front();
	m_pEnemy2Pool.pop_front();
	m_pEnemy2Pool.push_back(enemy2);
	return enemy2;
}

std::list<Enemy1*> EnemyManager::getENemy1Pool()
{
	return m_pEnemy1Pool;
}

std::list<Enemy2*> EnemyManager::getEnemy2Pool()
{
	return m_pEnemy2Pool;
}

void EnemyManager::update()
{
	for(auto enemy1 : m_pEnemy1Pool)
	{
		if(enemy1->isActivated())
		{
			enemy1->update();
		}
	}
	for (auto enemy2 : m_pEnemy2Pool)
	{
		if (enemy2->isActivated())
		{
			enemy2->update();
		}
	}
}

void EnemyManager::draw()
{
	for (auto enemy1 : m_pEnemy1Pool)
	{
		if (enemy1->isActivated())
		{
			enemy1->draw();
		}
	}
	for (auto enemy2 : m_pEnemy2Pool)
	{
		if (enemy2->isActivated())
		{
			enemy2->draw();
		}
	}
}

void EnemyManager::buildEnemy1Pool()
{
	m_pEnemy1Pool.clear();
	m_pEnemy1Pool = std::list<Enemy1*>();

	for (int i = 0; i < m_Enemy1Number; i++)
	{
		m_pEnemy1Pool.push_back(new Enemy1());
	}
}

void EnemyManager::buildEnemy2Pool()
{
	m_pEnemy2Pool.clear();
	m_pEnemy2Pool = std::list<Enemy2*>();

	for (int i = 0; i < m_Enemy2Number; i++)
	{
		m_pEnemy2Pool.push_back(new Enemy2());
	}
}
