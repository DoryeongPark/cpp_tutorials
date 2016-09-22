#pragma once
#include "Player.h"
#include "Game.h"
#include "Common.h"
#include "Point.h"
#include <cstdlib>
#include <ctime>
#include <vector>
class Challenger : Player
{
public:
	Challenger();
	Point input();
	void checkMineInfo(Point p);
	void checkBoardInfo(Point p, int value);
private:
	int weightedboard[BOARD_SIZE][BOARD_SIZE];
	int weight[BOARD_SIZE][BOARD_SIZE];
};