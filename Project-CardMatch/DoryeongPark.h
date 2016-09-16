#ifndef DORYEONGPARK_H
#define DORYEONGPARK_H
#include "Common.h"
#include "Player.h"

/*
	M2010112406

	Author			:	Doryeong Park
	S/N				:	2010112406
	Description		:	Program which picks two same number cards within two chances.  

	-	Class members
	
	point_order		:	Functor	which defines Point class instance's order.
	monitor			:	Data structure storing remaining Point instances matching with their card numbers.
						(Key : card number, Value : matching points)
	card_info		:	Data structure showing how many cards of each are remaining.
	state			:	Table showing all points' state. (UNKOWN / DISCOVERED / BLOCKED)
	card_table		:	Table showing points and matching card number including history.

	point_passer	:	Buffer to trasfer point to input second. 
	
	latest_card		:	Card number of latest discovered point.

	-	Member function

	pickSamePair	:	Checks it has same cards in monitor. If it finds pair of same cards, 
						returns true and returns one point of pair as parameter.
	updateMonitor	:	To sure to point which of state is DISCOVERED be in monitor, 
						checks state table and inserts all DISCOVERED points in monitor.

	existInMonitor	:	Determines if parameter point is in monitor or not.


*/
#include <vector>	
#include <map>
#include <algorithm>

class DoryeongPark : public Player
{
private:

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

	map<int, vector<Point>> monitor;
	map<int, int> card_info;
	map<Point, int, point_order> state;
	map<Point, int, point_order> card_table;
	
	vector<Point> point_passer;

	const int BLOCKED = -2;
	const int UNKNOWN = -1;
	const int DISCOVERED = 0;

	int latest_card = 0;

public:
	DoryeongPark();	
	Point inputFirst();
	Point inputSecond();
	void checkCardInfo(Point point, int card);
	void matchedCard(Point p1, Point p2, int card);
private:
	bool pickSamePair(Point& p);
	void updateMonitor();
	bool existInMonitor(Point p);
};
#endif