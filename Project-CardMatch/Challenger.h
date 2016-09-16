#ifndef Challenger_H
#define Challenger_H
#include "Common.h"
#include "Player.h"
#include "Game.h"

/*���*/
typedef struct tagNode Node;
typedef struct tagNode {
	int value;
	int x, y;//��ǥ
	Node* next;
}Node;
typedef Node* Np;
/*�ؽ����̺�*/
typedef struct HashTable {
	Np* table;
	int tableSize;
}HashTable;

class Challenger : public Player
{
	HashTable *ht;
	int check;//ù�������ֱ⿡�� �ϳ����ִ°� ã����
	int HashArray[LAST_CARD_NUMBER + 1];//���� �󸶳��ִ���
	int xyArray[BOARD_SIZE][BOARD_SIZE];//��ǥ�迭
	int CardArr[LAST_CARD_NUMBER];//ã�� ��ġī��
	Point p1;//ù��°�� �����Һ���
	int same;//������Ȯ�κ���
	int gru;//ó������Ȯ�κ���
public :

	HashTable* CreateHash(int size);//�ؽ����̺����
	Np CreateNode(int value,int x,int y);//��常���
	void Data_set(HashTable* ht, int x,int y, int value);//������ �ֱ�
	bool FindData(HashTable *ht,int x, int y, int value);//������ ã��(������Ʈ��)
	void Pop(HashTable *ht,Point p,int value);

	Challenger();
	int SameValue();//���������ֳ�
	Point inputFirst();
	Point inputSecond();
	bool checkboardRange(int x, int y);
	void checkCardInfo(Point point, int card);
	void matchedCard(Point p1, Point p2, int card);
};
#endif