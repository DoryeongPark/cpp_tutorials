#include "Challenger.h"

#include <iostream>
//for TEST


//��ģ ī��Ʈ�� ��������!
// 0 0 * 0 0 
// 0 1 * 1 0
// 0 0 * 0 0

//Ȯ���� ?
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
	//���ڰ� �������ν� �ǹ̾����� ����ġ���� ����
	//cout << "^";
	int x = p.getX(), y = p.getY();
	weight[y][x] = -1;			// �ڱ��ڽ��� �����̹Ƿ� flag�� -1
	weightedboard[y][x] = -1;	// �ڽ��� ��ġ�� ���� �߰� �����Ƿ� ����ġ -1
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (weight[y + i][x + j]>0)	// �����ֺ��̰� flag�� 1 �̻��� ����
			{
				weight[y + i][x + j]--;	// ���ڰ� �߰߉����Ƿ� flag�� 1 ����
				if (weight[y + i][x + j] == 0)	// �׸��� flag�� 0�� ��ٸ�
				{
					for (int k = -1; k <= 1; k++)
						for (int l = -1; l <= 1; l++)
							if (k != 0 || l != 0)
								weightedboard[y + i + k][x + j + l] = -1;
								// flag 0 �α��� ��� ����ġ�� -1��
				}
				else
				{				// flag�� 0�� �ƴѰ��
					for (int k = -1; k <= 1; k++)
						for (int l = -1; l <= 1; l++)
							if (k != 0 || l != 0)
								if(weightedboard[y + i + k][x + j + l] > -1)
									weightedboard[y + i + k][x + j + l]--;
								// flag �α��� ����ġ�� 1�� ����
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
	if (value == 0)	// �ֺ��� �ƹ��͵� �����Ƿ�
	{
		for (int i = -1; i <= 1; i++)
			for (int j = -1; j <= 1; j++)	// �ڱ� �ڽ��� ������ �α��� ����ġ�� -1��
			{
				if (Point(y + i, x + j).checkBoardRange() == false) continue;
				weightedboard[y + i][x + j] = -1;
			}
		//
	}
	else
	{	// �ֺ��� ���ڰ� ������
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