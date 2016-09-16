#ifndef Challenger_H
#define Challenger_H
#include "Common.h"
#include "Player.h"
#include "Game.h"

/*노드*/
typedef struct tagNode Node;
typedef struct tagNode {
	int value;
	int x, y;//좌표
	Node* next;
}Node;
typedef Node* Np;
/*해시테이블*/
typedef struct HashTable {
	Np* table;
	int tableSize;
}HashTable;

class Challenger : public Player
{
	HashTable *ht;
	int check;//첫번쨰값넣기에서 하나만있는거 찾을때
	int HashArray[LAST_CARD_NUMBER + 1];//값이 얼마나있는지
	int xyArray[BOARD_SIZE][BOARD_SIZE];//좌표배열
	int CardArr[LAST_CARD_NUMBER];//찾은 매치카드
	Point p1;//첫번째꺼 저장할변수
	int same;//같은값확인변수
	int gru;//처음꺼값확인변수
public :

	HashTable* CreateHash(int size);//해시테이블생성
	Np CreateNode(int value,int x,int y);//노드만들기
	void Data_set(HashTable* ht, int x,int y, int value);//데이터 넣기
	bool FindData(HashTable *ht,int x, int y, int value);//데이터 찾기(있으면트루)
	void Pop(HashTable *ht,Point p,int value);

	Challenger();
	int SameValue();//같은값이있나
	Point inputFirst();
	Point inputSecond();
	bool checkboardRange(int x, int y);
	void checkCardInfo(Point point, int card);
	void matchedCard(Point p1, Point p2, int card);
};
#endif