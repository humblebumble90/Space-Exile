#pragma once
#ifndef __SCOREBOARD__
#define __SCOREBOARD__
#include <string>
#include <vector>

class Scoreboard
{
	//this is for carrying your lives over to the other scenes
public:
	static Scoreboard* Instance()
	{
		if (instance == nullptr)
		{
			instance = new Scoreboard();
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
	Scoreboard();
	~Scoreboard();

	int hp;
	int score;
	int highScore;
	static Scoreboard* instance;
};

#endif 