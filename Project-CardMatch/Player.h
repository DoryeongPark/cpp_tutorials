#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player
{
public:
	Player()
	{		
	}
	//ù ��° ī�带 ������ ��ġ�� ��ȯ�ϸ� ��.
	virtual Point inputFirst() = 0;
	//�� ��° ī�带 ������ ��ġ�� ��ȯ�ϸ� ��.
	virtual Point inputSecond() = 0;
	//������ ī���� ��ġ�� ���� ���ڸ� �Ű������� �־���.
	virtual void checkCardInfo(Point point, int card) = 0;
	//��Ī�� �� ��� �� ī���� ��ġ�� ī���� ��ȣ�� �Ű������� �־���.
	virtual void matchedCard(Point p1, Point p2, int card) = 0;
};
#endif