#ifndef DORYEONGPARK_H
#define DORYEONGPARK_H
#include "Common.h"
#include "Point.h"


/* 
	M2010112406

	Author		:	Doryeong Park
	Date		:	2016. 5. 15
	Description	:	class with probablity table update algorithm
	
	동작원리 설명	:	상대방 또는 자신이 한 공간을 들어낼 때마다 갱신한 정보 테이블을 바탕으로 확률 테이블을 갱신하여
					지뢰가 있을 확률이 가장 높은 공간을 가장 먼저 선택하여 들어낸다.

	※	Class Members
	
	- Variables
	
	point_order			:	Ascending order for tables
	monitor				:	Table for uncovered information(Unknown point, Mine point, Number of mines around).
	prob_table			:	Table showing calculated probablity of each points.(0 < p < 1)  
	visited				:	Flag table for showing points whether it was uncovered or not.
	reduce_reservation	:	Storage for points which need to reduce number of mines.

	- Functions(Public)

	Default constructor	:	Initiates 3 tables as filling UNKNOWN value or false.
	input				:	Suggests highest probability point to game manager.
	checkMineInfo		:	Gets uncovered mine point from game manager. Updates probability table with the point.
	checkBoardInfo		:	Gets uncovered point from game manager. Updates probability table with the point.

	- Functions(Private)

	distribute_prob		:	Distributes probability to 8 points around points uncovered. 
	update_prob_table	:	Updates probability table as monitor table changes.
	expand_zero			:	If mine number of uncovered point is zero, makes 8 points around the point denying access.(visited flag == true)
	get_highest			:	Get highest probability point from probability table.
	mine_reduce_effect	:	If mine's uncovered, updates information of 8 points around mine.

*/

#include <map>
#include <vector>
#include <algorithm>
#include <random>

constexpr int UNKNOWN = -2;

class DoryeongPark
{
	struct point_order {
		bool operator()(Point p1, Point p2) const {
			if (p1.getX() == p2.getX()) {
				if (p1.getY() > p2.getY())
					return true;
				else
					return false;
			}
			else if (p1.getX() > p2.getX())
				return true;

			else
				return false;

		}
	};
	
	map<Point, int, point_order> monitor;
	map<Point, double, point_order> prob_table;
	map<Point, bool, point_order> visited;
	vector<Point> reduce_reservation;

public :
	DoryeongPark();
	Point input() noexcept;
	void checkMineInfo(const Point p) noexcept;
	void checkBoardInfo(const Point& p, const int value) noexcept;
private:
	void distribute_prob(Point p) noexcept;
	void update_prob_table() noexcept;
	void expand_zero(Point p) noexcept;
	Point get_highest() noexcept;
	void mine_reduce_effect(Point p) noexcept;
};
#endif