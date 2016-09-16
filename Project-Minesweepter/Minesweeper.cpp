#include<time.h>
#include "GameManager.h"
int main()
{
	srand((unsigned int)time(NULL));
	GameManager gm;
	gm.play();
	return 0;
}