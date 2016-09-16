#include "common.h"
#include "student.h"
Assistant::Assistant()
{
}

Point Assistant::input()
{
	//랜덤위치를 확인하기 위해
	//p를 설정하여 반환
	Point p(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
	return p;
}

void Assistant::checkMineInfo(Point p)
{
}

void Assistant::checkBoardInfo(Point p, int value)
{
}