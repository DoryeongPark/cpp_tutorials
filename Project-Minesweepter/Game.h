#ifndef GAME_H
#define GAME_H

#include "Point.h"
#include "Common.h"
class Game
{
private:
	//플레이할 보드판
	int board[BOARD_SIZE][BOARD_SIZE];
	//오픈된 위치를 표시
	bool isOpend[BOARD_SIZE][BOARD_SIZE];

	//지뢰를 매복시키는 메소드
	//Game 클래스 외부에서 사용하지 않도록 private
	void insertMine(Point p);
public:
	Game();
	//특정 위치에 있는 값을 반환
	int getBoardInfo(Point p);

	//특정 위치가 확인된 지뢰인지 체크
	bool checkOpend(Point p);

	//특정 위치가 열렸다고 표시
	void setOpend(Point p);
};

#endif