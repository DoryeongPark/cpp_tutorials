#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player
{
public:
	Player()
	{		
	}
	//첫 번째 카드를 뒤집을 위치를 반환하면 됨.
	virtual Point inputFirst() = 0;
	//두 번째 카드를 뒤집을 위치를 반환하면 됨.
	virtual Point inputSecond() = 0;
	//뒤집힌 카드의 위치와 적힌 숫자를 매개변수로 넣어줌.
	virtual void checkCardInfo(Point point, int card) = 0;
	//매칭이 된 경우 두 카드의 위치와 카드의 번호를 매개변수로 넣어줌.
	virtual void matchedCard(Point p1, Point p2, int card) = 0;
};
#endif