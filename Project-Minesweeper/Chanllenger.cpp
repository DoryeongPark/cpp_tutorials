#include "Challenger.h"

#include <iostream>
//for TEST


//겹친 카운트가 많을수록!
// 0 0 * 0 0 
// 0 1 * 1 0
// 0 0 * 0 0

//확률은 ?
// x x x ? ? ?
// x 2 ? ? 8 ?
// x x ? ? ? ?

using namespace std;
Challenger::Challenger()
{
	srand(time(NULL));
	for (int y = 0; y < BOARD_SIZE; y++)
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			weightedboard[y][x] = 1;
			weight[y][x] = -1;
		}

}

Point Challenger::input()
{
	// main Algorithm
	int highest_weight = -1;
	vector<Point> candidate_point;
	int xx, yy;
	for (int y = 0; y < BOARD_SIZE; y++)
		for (int x = 0; x < BOARD_SIZE; x++)
			if (weightedboard[y][x] > highest_weight)
			{
				highest_weight = weightedboard[y][x];
				xx = x;
				yy = y;
			}
	for (int y = 0; y < BOARD_SIZE; y++)
		for (int x = 0; x < BOARD_SIZE; x++)
			if (weightedboard[y][x] == highest_weight)
				candidate_point.push_back(Point(x, y));
	Point retp = candidate_point[rand() % candidate_point.size()];
	candidate_point.clear();

	//cout << "Player 2 - " << retp << endl;
	return retp;
}
void Challenger::checkMineInfo(Point p)
{
	//지뢰가 생김으로써 의미없어진 가중치들을 제거
	//cout << "^";
	int x = p.getX(), y = p.getY();
	weight[y][x] = -1;			// 자기자신이 지뢰이므로 flag를 -1
	weightedboard[y][x] = -1;	// 자신이 위치한 곳은 발견 됬으므로 가중치 -1
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (weight[y + i][x + j]>0)	// 지뢰주변이고 flag가 1 이상인 곳은
			{
				weight[y + i][x + j]--;	// 지뢰가 발견됬으므로 flag를 1 감소
				if (weight[y + i][x + j] == 0)	// 그리고 flag가 0이 됬다면
				{
					for (int k = -1; k <= 1; k++)
						for (int l = -1; l <= 1; l++)
							if (k != 0 || l != 0)
								weightedboard[y + i + k][x + j + l] = -1;
								// flag 0 인근의 모든 가중치를 -1로
				}
				else
				{				// flag가 0이 아닌경우
					for (int k = -1; k <= 1; k++)
						for (int l = -1; l <= 1; l++)
							if (k != 0 || l != 0)
								if(weightedboard[y + i + k][x + j + l] > -1)
									weightedboard[y + i + k][x + j + l]--;
								// flag 인근의 가중치를 1씩 감소
				}
			}
		}
	//cout << "^ ";
}
void Challenger::checkBoardInfo(Point p, int value)
{
	//cout << "&";
	int x = p.getX(), y = p.getY();
	//cout << x << " " << y << " " << value;
	weight[y][x] = value;
	if (value == 0)	// 주변에 아무것도 없으므로
	{
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)	// 자기 자신을 포함한 인근의 가중치를 -1로
			{
				if (Point(y + i, x + j).checkBoardRange() == false) continue;
				weightedboard[y + i][x + j] = -1;
			}
		//
	}
	else
	{	// 주변에 지뢰가 있으면
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)
			{
				if (Point(y + i, x + j).checkBoardRange() == false) continue;
				if (i != 0 || j != 0)
				{
					if (weightedboard[y + i][x + j] > -1)
						weightedboard[y + i][x + j] += 1;
				}
				else
					weightedboard[y + i][x + j] = -1;
			}
	}
	//cout << "& ";
}