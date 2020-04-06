/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 02-17-2020
 * Description: header file of enum that defines type of game objects.
 */
#pragma once
#ifndef __GAME_OBJECT_TYPE__
#define __GAME_OBJECT_TYPE__
enum GameObjectType {
	NONE = -1,
	ENEMY,
	PLAYER_LASER,
	PLAYER,
	START_BUTTON,
	EXIT_BUTTON,
	PLAY_SCENE_BG,
	START_SCENE_BG,
	TARGET,
	OBSTACLE,
	SHIP,
	NUM_OF_TYPES
};

#endif /* defined (__GAME_OBJECT_TYPE__)*/