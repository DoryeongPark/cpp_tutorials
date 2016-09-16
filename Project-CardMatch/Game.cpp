#include "Common.h"
#include "Game.h"
Game::Game()
{
	//1~LAST_CARD_NUMBER까지의 수를
	//SAME_CARD_COUNT만큼 만듬
	int randomCard[BOARD_SIZE*BOARD_SIZE] = {0};
	for(int i = 0 ; i < LAST_CARD_NUMBER; i++)
	{
		for(int j = 0 ; j < SAME_CARD_COUNT ; j++)
		{
			randomCard[i*SAME_CARD_COUNT + j] = i+1;
		}
	}

	//위에서 만든 값을 랜덤하게 섞음
	for(int i = 0 ; i < BOARD_SIZE*BOARD_SIZE ; i++)
	{
		int randomIndex = rand() % (BOARD_SIZE * BOARD_SIZE);
		int temp = randomCard[i];
		randomCard[i] = randomCard[randomIndex];
		randomCard[randomIndex] = temp;
	}

	//랜덤하게 만들어진 패를 board에 설정함
	for(int i = 0 ; i < BOARD_SIZE ; i++)
	{
		for(int j = 0 ; j < BOARD_SIZE ; j++)
		{
			board[i][j] = randomCard[i*BOARD_SIZE + j];
		}
	}

	//매칭 정보를 초기화함
	memset(matched, 0, sizeof(matched));
}

int Game::getCard(Point p)
{
	//p가 범위를 넘었으면 0 리턴
	if(p.checkBoardRange() == false)
		return 0;

	//p위치에 존재하는 값 리턴
	return board[p.getX()][p.getY()];
}

bool Game::tryMatching(Point p1, Point p2)
{
	//p1, p2가 범위를 벗어났으면 false
	if(p1.checkBoardRange() == false)
		return false;
	if(p2.checkBoardRange() == false)
		return false;

	//p1과 p2가 같은 지점이면 false
	if (p1 == p2)
		return false;

	//p1이나 p2 중 하나라도 매칭되었다면 false
	if(matched[p1.getX()][p1.getY()] || matched[p2.getX()][p2.getY()])
		return false;

	//p1, p2가 짝일 경우 true
	if(board[p1.getX()][p1.getY()] == board[p2.getX()][p2.getY()])
	{
		matched[p1.getX()][p1.getY()] = true;
		matched[p2.getX()][p2.getY()] = true;
		return true;
	}

	//그 외 모든 경우 false
	return false;
}