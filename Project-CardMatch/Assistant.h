#ifndef ASSISTANT_H
#define ASSISTANT_H
#include <list>
#include "Common.h"
#include "Player.h"
class Assistant : public Player
{
public :
	Assistant();	
	Point inputFirst();
	Point inputSecond();
	void checkCardInfo(Point point, int card);
	void matchedCard(Point p1, Point p2, int card);
};
#endif