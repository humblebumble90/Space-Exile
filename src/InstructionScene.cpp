#include "InstructionScene.h"
#include <SDL.h>
#include "Game.h"

InstructionScene::InstructionScene()
{
	start();
}

InstructionScene::~InstructionScene()
{
}

void InstructionScene::draw()
{
	m_pInstruction->draw();
}

void InstructionScene::update()
{
}

void InstructionScene::clean()
{
	delete m_pInstruction;
	removeAllChildren();
}

void InstructionScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_SPACE:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void InstructionScene::start()
{
	m_pInstruction = new Instruction();
	m_pInstruction->setParent(this);
	addChild(m_pInstruction);
}
