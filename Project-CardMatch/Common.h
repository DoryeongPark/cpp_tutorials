#ifndef COMMON_H
#define COMMON_H

//한 숫자당 몇개의 짝이 존재하는지
#define SAME_CARD_COUNT 8

//보드의 크기
#define BOARD_SIZE 100

//1~LAST_CARD_NUMBER의 숫자가 나옴
#define LAST_CARD_NUMBER (BOARD_SIZE*BOARD_SIZE)/SAME_CARD_COUNT

#include <iostream>
using namespace std;

#endif