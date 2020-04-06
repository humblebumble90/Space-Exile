/*
 * Author: 'Phillip' Hyungseok lee.
 * Reference: Provided several templates from the professor Tom Tsiliopoulos's 2020 Winter COMP397 course.
 * StudentNumber: 301011097
 * Written date : 04-06-2020
 * Description: Scoreboard to display score, lives, and highscore
 */
#pragma once
#ifndef __SCOREBOARD__
#define __SCOREBOARD__
#include <string>
#include <vector>

class ScoreBoard
{
	//this is for carrying your lives over to the other scenes
public:
	static ScoreBoard* Instance()
	{
		if (instance == nullptr)
		{
			instance = new ScoreBoard();
			return instance;
		}
		return instance;
	}
	int getHP();
	void setHP(int HP);
	int getScore();
	void setScore(int setScore);
	int getHighScore();
	void setHighScore(int num);
	void resetValues();

private:
	ScoreBoard();
	~ScoreBoard();

	int hp;
	int score;
	int highScore;
	static ScoreBoard* instance;
};

#endif 