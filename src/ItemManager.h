/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Item manager built in object pooling way.
 */
#pragma once
#ifndef __ITEM_MANAGER__
#define __ITEM_MANAGER__
#include <list>
#include "Shield.h"
#include "PowerUp.h"
#endif/*Defined(__ITEM_MANAGER__)*/

class ItemManager
{
public:
	static ItemManager* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new ItemManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void clean();

	Shield* getShield();
	std::list<Shield*> getShieldPool();
	PowerUp* getPowerUp();
	std::list<PowerUp*> getPowerUpPool();

	void update();
	void draw();
	
	void buildShieldPool();
	void buildPowerUpPool();
private:
	ItemManager();
	~ItemManager();

	int m_shieldNum;
	int m_powerUpNum;

	static ItemManager* s_pInstance;

	std::list<Shield*> m_pShieldPool;
	std::list<PowerUp*> m_pPowerUpPool;
};