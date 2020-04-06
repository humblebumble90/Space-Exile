#include "ItemManager.h"
ItemManager* ItemManager::s_pInstance = nullptr;

ItemManager::ItemManager():m_shieldNum(10),m_powerUpNum(10)
{
	buildShieldPool();
	buildPowerUpPool();
}

ItemManager::~ItemManager()
= default;

void ItemManager::clean()
{
}

Shield* ItemManager::getShield()
{
	auto shield = m_pShieldPool.front();
	m_pShieldPool.pop_front();
	m_pShieldPool.push_back(shield);
	return shield;
}

std::list<Shield*> ItemManager::getShieldPool()
{
	return m_pShieldPool;
}

PowerUp* ItemManager::getPowerUp()
{
	auto powerUp = m_pPowerUpPool.front();
	m_pPowerUpPool.pop_front();
	m_pPowerUpPool.push_back(powerUp);
	return powerUp;
}

std::list<PowerUp*> ItemManager::getPowerUpPool()
{
	return m_pPowerUpPool;
}

void ItemManager::buildPowerUpPool()
{
	m_pPowerUpPool = std::list<PowerUp*>();
	for (int i = 0; i < m_powerUpNum; ++i)
	{
		m_pPowerUpPool.push_back(new PowerUp());
	}
}

void ItemManager::update()
{
	for (auto shield : m_pShieldPool)
	{
		if(shield->isActivated())
		{
			shield->update();
		}
	}
	for(auto powerUp : m_pPowerUpPool)
	{
		if(powerUp->isActivated())
		{
			powerUp->update();
		}
	}
}

void ItemManager::draw()
{
	for (auto shield : m_pShieldPool)
	{
		if (shield->isActivated())
		{
			shield->draw();
		}
	}
	for (auto powerUp : m_pPowerUpPool)
	{
		if (powerUp->isActivated())
		{
			powerUp->draw();
		}
	}
}

void ItemManager::buildShieldPool()
{
	if(m_pShieldPool.size() > 0)
	{
		m_pShieldPool.clear();
	}
	m_pShieldPool = std::list<Shield*>();
	for (int i = 0; i < m_shieldNum; ++i)
	{
		m_pShieldPool.push_back(new Shield());
	}
}