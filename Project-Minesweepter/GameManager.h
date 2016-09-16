#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H
#include "Common.h"
#include "Student.h"
#include "DoryeongPark.h"
#include "Challenger.h"
#include "Game.h"

class GameManager
{
private :
	//������ �÷����� player1�� player2
	DoryeongPark player1;
	Challenger player2;
	
	//���� Game����
	Game game;
	
	//�÷��̾���� ������ ������ ����
	int player1Score;
	int player2Score;
public :
	GameManager();

	//������ �÷����� �޼ҵ�
	void play();
};
#endif