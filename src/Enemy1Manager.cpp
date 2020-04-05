#include "Enemy1Manager.h"

Enemy1Manager* Enemy1Manager::s_pInstance = nullptr;

Enemy1Manager::Enemy1Manager():m_Enemy1Number(10)
{
	m_buildEnemy1Pool();
}

Enemy1Manager::~Enemy1Manager()
= default;

void Enemy1Manager::clean()
{
}

Enemy1* Enemy1Manager::getEnemy1()
{
	Enemy1* enemy1 = m_pEnemy1Pool.front();
	m_pEnemy1Pool.pop_front();
	m_pEnemy1Pool.push_back(enemy1);
	return enemy1;
}

void Enemy1Manager::update()
{
	for(auto enemy1 : m_pEnemy1Pool)
	{
		if(enemy1->isActivated())
		{
			enemy1->update();
		}
	}
}

void Enemy1Manager::draw()
{
	for (auto enemy1 : m_pEnemy1Pool)
	{
		if (enemy1->isActivated())
		{
			enemy1->draw();
		}
	}
}

void Enemy1Manager::m_buildEnemy1Pool()
{
	m_pEnemy1Pool = std::list<Enemy1*>();

	for (int i = 0; i < m_Enemy1Number; i++)
	{
		m_pEnemy1Pool.push_back(new Enemy1());
	}
}
