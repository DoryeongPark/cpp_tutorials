#include "Common.h"
#include "Game.h"
Game::Game()
{
	//1~LAST_CARD_NUMBER������ ����
	//SAME_CARD_COUNT��ŭ ����
	int randomCard[BOARD_SIZE*BOARD_SIZE] = {0};
	for(int i = 0 ; i < LAST_CARD_NUMBER; i++)
	{
		for(int j = 0 ; j < SAME_CARD_COUNT ; j++)
		{
			randomCard[i*SAME_CARD_COUNT + j] = i+1;
		}
	}

	//������ ���� ���� �����ϰ� ����
	for(int i = 0 ; i < BOARD_SIZE*BOARD_SIZE ; i++)
	{
		int randomIndex = rand() % (BOARD_SIZE * BOARD_SIZE);
		int temp = randomCard[i];
		randomCard[i] = randomCard[randomIndex];
		randomCard[randomIndex] = temp;
	}

	//�����ϰ� ������� �и� board�� ������
	for(int i = 0 ; i < BOARD_SIZE ; i++)
	{
		for(int j = 0 ; j < BOARD_SIZE ; j++)
		{
			board[i][j] = randomCard[i*BOARD_SIZE + j];
		}
	}

	//��Ī ������ �ʱ�ȭ��
	memset(matched, 0, sizeof(matched));
}

int Game::getCard(Point p)
{
	//p�� ������ �Ѿ����� 0 ����
	if(p.checkBoardRange() == false)
		return 0;

	//p��ġ�� �����ϴ� �� ����
	return board[p.getX()][p.getY()];
}

bool Game::tryMatching(Point p1, Point p2)
{
	//p1, p2�� ������ ������� false
	if(p1.checkBoardRange() == false)
		return false;
	if(p2.checkBoardRange() == false)
		return false;

	//p1�� p2�� ���� �����̸� false
	if (p1 == p2)
		return false;

	//p1�̳� p2 �� �ϳ��� ��Ī�Ǿ��ٸ� false
	if(matched[p1.getX()][p1.getY()] || matched[p2.getX()][p2.getY()])
		return false;

	//p1, p2�� ¦�� ��� true
	if(board[p1.getX()][p1.getY()] == board[p2.getX()][p2.getY()])
	{
		matched[p1.getX()][p1.getY()] = true;
		matched[p2.getX()][p2.getY()] = true;
		return true;
	}

	//�� �� ��� ��� false
	return false;
}