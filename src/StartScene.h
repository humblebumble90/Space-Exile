#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "Label.h"
#include "StartButton.h"
#include "Start_Scene_Bg.h"
#include "ExitButton.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// Game Objects
	Label* m_pStartLabel;
	StartButton* m_pStartButton;
	ExitButton* m_pExitButton;
	Start_Scene_Bg* m_pStart_Scene_Bg;

	// private data member
	glm::vec2 m_mousePosition;
	
};

#endif /* defined (__START_SCENE__) */