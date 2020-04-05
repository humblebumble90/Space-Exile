#include "PlayScene.h"

PlayScene::PlayScene()
{
	start();
}

PlayScene::~PlayScene()
{
}

void PlayScene::draw()
{
	m_pMap1->draw();
	m_pMap2->draw();
}

void PlayScene::update()
{
	m_pMap1->update();
	m_pMap2->update();
}

void PlayScene::clean()
{
}

void PlayScene::handleEvents()
{
}

void PlayScene::start()
{
	m_pMap1 = new Map();
	m_pMap1->setPosition(glm::vec2(-1280.0f,0.0f));
	m_pMap1->setParent(this);
	addChild(m_pMap1);
	m_pMap2 = new Map();
	m_pMap2->setPosition(glm::vec2(0.0f, 0.0f));
	m_pMap2->setParent(this);
	addChild(m_pMap2);
}
