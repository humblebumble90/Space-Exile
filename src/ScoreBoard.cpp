#include "ScoreBoard.h"
#include <ostream>
#include <iostream>

Scoreboard* Scoreboard::instance = nullptr;

Scoreboard::Scoreboard()
{
	resetValues();
}

Scoreboard::~Scoreboard()
= default;

void Scoreboard::resetValues()
{
	hp = 5;
	score = 0;
	highScore = 0;
}

int Scoreboard::getHP()
{
	return hp;
}

void Scoreboard::setHP(int HP)
{
	hp = HP;
}

int Scoreboard::getScore()
{
	return score;
}

int Scoreboard::getHighScore()
{
	return highScore;
}

void Scoreboard::setScore(int Score)
{
	score += Score;
	std::cout << "Current score: " + std::to_string(score) << std::endl;
	if (score >= highScore)
	{
		setHighScore(score);
	}
}

void Scoreboard::setHighScore(int num)
{
	std::cout << "Current HighScore: " + std::to_string(highScore) << std::endl;
	highScore = num;
}




