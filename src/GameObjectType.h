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
	START_BUTTON,
	EXIT_BUTTON,
	PLAY_SCENE_BG,
	START_SCENE_BG,
	NUM_OF_TYPES
};

#endif /* defined (__GAME_OBJECT_TYPE__)*/