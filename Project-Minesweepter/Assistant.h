#ifndef ASSISTANT
#define ASSISTANT
#include "Player.h"
class Assistant : public Player
{
private :
public :
	Assistant();
	Point input();
	void checkMineInfo(Point p);
	void checkBoardInfo(Point p, int value);
};
#endif