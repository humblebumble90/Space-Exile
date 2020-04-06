#include "Instruction_btn.h"
#include "Game.h"

Instruction_btn::Instruction_btn()
	:Button(
		"../Assets/textures/instruction_btn.png",
		"instruction_btn",
		INSTRUCTION_BUTTON, glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f)), m_isClicked(false)
{
}

Instruction_btn::~Instruction_btn()
{
}

bool Instruction_btn::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->changeSceneState(INSTRUCTION_SCENE);
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
