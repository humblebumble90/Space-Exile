#include "ScoreBoard.h"
#include <ostream>
#include <iostream>

ScoreBoard* ScoreBoard::instance = nullptr;

ScoreBoard::ScoreBoard()
{
	hp = 5;
	score = 0;
	highScore = 0;
}

ScoreBoard::~ScoreBoard()
= default;

void ScoreBoard::resetValues()
{
	hp = 5;
	score = 0;
}

int ScoreBoard::getHP()
{
	return hp;
}

void ScoreBoard::setHP(int HP)
{
	hp = HP;
}

int ScoreBoard::getScore()
{
	return score;
}

int ScoreBoard::getHighScore()
{
	return highScore;
}

void ScoreBoard::setScore(int Score)
{
	score += Score;
	std::cout << "Current score: " + std::to_string(score) << std::endl;
	if (score >= highScore)
	{
		setHighScore(score);
	}
}

void ScoreBoard::setHighScore(int num)
{
	std::cout << "Current HighScore: " + std::to_string(highScore) << std::endl;
	highScore = num;
}




