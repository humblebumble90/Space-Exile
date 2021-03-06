/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: The cpp file of start-button that allows user to go to the play scene.
 */
#include "StartScene.h"
#include "Game.h"
#include <iomanip>

StartScene::StartScene()
{
	start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	m_pStart_Scene_Bg->draw();
	m_pStartLabel->draw();
	m_pStartButton->draw();
	m_pExitButton->draw();
	m_pInstruction_btn->draw();
	
}

void StartScene::update()
{
	m_pStartButton->setMousePosition(m_mousePosition);
	if(m_pStartButton->ButtonClick())
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
	m_pInstruction_btn->setMousePosition(m_mousePosition);
	if(m_pInstruction_btn->ButtonClick())
	{
		Game::Instance()->changeSceneState(INSTRUCTION_SCENE);
	}
	m_pExitButton->setMousePosition(m_mousePosition);
	if(m_pExitButton->ButtonClick())
	{
		Game::Instance()->quit();
	}
}

void StartScene::clean()
{
	delete m_pStart_Scene_Bg;
	delete m_pStartLabel;
	//delete m_pStartButton;
	//delete m_pInstruction_btn;
	//delete m_pExitButton;
	TheSoundManager::Instance()->clear();
	removeAllChildren();
}

void StartScene::handleEvents()
{
	int wheel = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(true);
				m_pExitButton->setMouseButtonClicked(true);
				m_pInstruction_btn->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pStartButton->setMouseButtonClicked(false);
				m_pExitButton->setMouseButtonClicked(false);
				m_pInstruction_btn->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;





			
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_SPACE:
				TheGame::Instance()->changeSceneState(SceneState::PLAY_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void StartScene::start()
{
	m_pStart_Scene_Bg = new Start_Scene_Bg();
	addChild(m_pStart_Scene_Bg);
	
	SDL_Color color = { 255, 200,200, 255 };
	m_pStartLabel = new Label("Space Exile", "QuirkyRobot", 80, color, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.25f)
	,TTF_STYLE_BOLD,true);
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);
	
	m_pStartButton = new StartButton();
	m_pStartButton->setPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.25f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pStartButton);
	m_pInstruction_btn = new Instruction_btn();
	m_pInstruction_btn->setParent(this);
	addChild(m_pInstruction_btn);
	m_pExitButton = new ExitButton();
	m_pExitButton->setPosition
	(glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.9f));
	addChild(m_pExitButton);

	SoundManager::Instance()->load("../Assets/audio/startScene_theme.ogg",
		"startScene_theme", SOUND_MUSIC);
	SoundManager::Instance()->playMusic("startScene_theme", 999);
}

glm::vec2 StartScene::getMousePosition()
{
	return m_mousePosition;
}
