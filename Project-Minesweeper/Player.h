#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player
{
public :
	Player()
	{
	}
	//확인해보고 싶은 위치를 반환
	virtual Point input()=0;
	//확인한 위치에 지뢰가 있을 경우 호출될 메소드(지뢰 위치 p)
	virtual void checkMineInfo(Point p)=0;
	//확인한 위치에 지뢰가 없을 경우 호출될 메소드
	//(지뢰 위치 p, 인접 8방향에 존재하는 지뢰의 수)
	virtual void checkBoardInfo(Point p, int value)=0;
};

#endif