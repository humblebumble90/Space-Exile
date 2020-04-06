#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_pBg->draw();
	m_Label->draw();
}

void EndScene::update()
{
}

void EndScene::clean()
{
	delete m_Label;
	removeAllChildren();
}

void EndScene::handleEvents()
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
			case SDLK_r:
				TheGame::Instance()->changeSceneState(SceneState::PLAY_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void EndScene::start()
{
	m_pBg = new Endscene_Bg();
	m_pBg->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, 
		Config::SCREEN_HEIGHT * 0.25f));
	m_pBg->setParent(this);
	addChild(m_pBg);
	SDL_Color color = { 0,0, 0, 255 };
	m_Label = new Label("Press R to restart the game.",
		"QuirkyRobot", 80, color, 
		glm::vec2(Config::SCREEN_WIDTH*0.5f, Config::SCREEN_HEIGHT*0.75f));
	m_Label->setParent(this);
	addChild(m_Label);


	SoundManager::Instance()->load("../Assets/audio/endScene_theme.ogg",
		"endScene_theme", SOUND_MUSIC);
	SoundManager::Instance()->playMusic("endScene_theme", 999);
}
