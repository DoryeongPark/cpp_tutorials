#include "Game.h"
Game::Game()
{
	//지뢰 위치를 랜덤하게 생성해서 저장함
	//단, 중복된 위치가 존재하지 않도록 함
	Point randomMinePosition[MINE_COUNT];
	for(int i = 0 ; i < MINE_COUNT ; i++)
	{
		Point p = Point(rand()%BOARD_SIZE, rand()%BOARD_SIZE);
		bool isFind = false;
		for(int j = 0 ; j < i ; j++)
		{
			if(randomMinePosition[j] == p)
			{
				isFind = true;
				break;
			}
		}
		if(isFind) i--;
		else randomMinePosition[i] = p;
	}

	//보드를 0으로 초기화함
	memset(board, 0, sizeof(board));

	//모든 위치를 열어보지 않은 것으로 초기화함
	memset(isOpend, 0, sizeof(isOpend));

	//실제 보드에 지뢰를 매복함
	for(int i = 0 ; i < MINE_COUNT ; i++)
	{
		insertMine(randomMinePosition[i]);
	}
}
void Game::insertMine(Point p)
{
	//지뢰를 기준으로 8방향을 확인하기 위해 위치 정보
	const int x[] = { -1, -1, -1, 0, 0, 1, 1, 1};
	const int y[] = { -1, 0, 1, -1, 1, -1, 0, 1};

	int _x = p.getX(), _y = p.getY();
	for(int i = 0 ; i < 8 ; i++)
	{
		//8방향을 확인하면서
		//보드 범위 이내이고 지뢰가 아니면 1을 더함
		Point newP = Point(_x + x[i], _y + y[i]);
		if(newP.checkBoardRange())
		{
			if(board[ newP.getX() ][ newP.getY() ] == -1)
				continue;
			board[ newP.getX() ][ newP.getY() ]++;
		}
	}

	//지뢰를 지정함
	board[ _x ][ _y ] = -1;
}
int Game::getBoardInfo(Point p)
{
	//범위가 벗어난 경우 0으로 지정
	if(p.checkBoardRange() == false)
		return 0;

	//그 외의 경우 해당 값 반환
	return board[p.getX()][p.getY()];
}

bool Game::checkOpend(Point p)
{
	return isOpend[p.getX()][p.getY()];
}

void Game::setOpend(Point p)
{
	isOpend[p.getX()][p.getY()] = true;
}