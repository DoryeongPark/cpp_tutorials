#ifndef GAME_H
#define GAME_H

#include "Point.h"
#include "Common.h"
class Game
{
private:
	//�÷����� ������
	int board[BOARD_SIZE][BOARD_SIZE];
	//��Ī�� �е��� ������ ����
	bool matched[BOARD_SIZE][BOARD_SIZE];
public:
	Game();
	//Ư�� ��ġ�� �ִ� ī�带 ��ȯ
	int getCard(Point point);
	//�� ī�带 ��Ī�Ǵ��� Ȯ����
	bool tryMatching(Point p1, Point p2);
};
#endif