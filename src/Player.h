/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Myself
 * StudentNumber: 301011097
 * Written date : 04-05-2020
 * Description: Implement loading player img, firing, moving, and other needed features.
 */
#pragma once
#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Config.h"
#include "Move.h"
#ifndef __PLAYER__
#define __PLAYER__
class Player:public DisplayObject
{
public:
    Player(std::string imagePath = "../Assets/textures/player.png",
        std::string name = "player",
        GameObjectType type = PLAYER,
        glm::vec2 position =
        glm::vec2(Config::SCREEN_WIDTH*0.2f,Config::SCREEN_HEIGHT*0.5f));
	 ~Player();
	
	void draw() override;
	void update() override;
	void clean() override;

    void move(Move newMove);
    void fire();
    void hit();

    bool getInvincible();
private:
    std::string m_name;
    Uint8 m_alpha;
	
    int hp;
    bool inv;
    float m_maxSpeed;
	
    float m_fireRate;
    float m_cooltime;
	
    void checkBound();

    void movebyState();
	
};
#endif/*Defined (__PLAYER__)*/