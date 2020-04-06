/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The cpp file of a exit-button. It quits game running.
 */
#include "ExitButton.h"
#include "Game.h"

ExitButton::ExitButton()
	:Button(
		"../Assets/textures/exit_btn.png",
		"ExitButton",
		EXIT_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.95f)), m_isClicked(false)
{
}

ExitButton::~ExitButton()
= default;

bool ExitButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
