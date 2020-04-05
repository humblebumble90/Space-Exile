/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The header file of a exit-button. It quits game running.
 */
#pragma once
#ifndef __EXIT_BUTTON__
#define __EXIT_BUTTON__

#include "Button.h"

class ExitButton: public Button
{
public:
	ExitButton();
	~ExitButton();
	
	bool ButtonClick() override;
private:
	bool m_isClicked;
};
#endif/*Defined(EXIT_BUTTON__)*/