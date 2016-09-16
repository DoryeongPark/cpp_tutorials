#include "Common.h"
#include "Assistant.h"
Assistant::Assistant()
{
}
Point Assistant::inputFirst()
{
	return Point(rand() % BOARD_SIZE, rand() % BOARD_SIZE);
}
Point Assistant::inputSecond()
{
	return Point(rand()%BOARD_SIZE, rand()%BOARD_SIZE);
}
void Assistant::checkCardInfo(Point p, int card)
{
}
void Assistant::matchedCard(Point _p1, Point _p2, int card)
{
}