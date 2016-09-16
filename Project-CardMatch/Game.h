#ifndef GAME_H
#define GAME_H

#include "Point.h"
#include "Common.h"
class Game
{
private:
	//플레이할 보드판
	int board[BOARD_SIZE][BOARD_SIZE];
	//매칭된 패들의 정보를 저장
	bool matched[BOARD_SIZE][BOARD_SIZE];
public:
	Game();
	//특정 위치에 있는 카드를 반환
	int getCard(Point point);
	//두 카드를 매칭되는지 확인함
	bool tryMatching(Point p1, Point p2);
};
#endif