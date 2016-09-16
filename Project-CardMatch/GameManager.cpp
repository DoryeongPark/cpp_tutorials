#include "GameManager.h"
GameManager::GameManager()
{
	//메니저가 생성될때 스코어 초기화
	player1Score = 0;
	player2Score = 0;
}
void GameManager::play()
{
	Point p1, p2;
	
	//시작할 플레이어를 랜덤으로 지정
	int turn = rand()%2;

	if(turn%2)
		cout << "Player1 Start" << endl;
	else
		cout << "Player2 Start" << endl;

	//총 카드를 뒤집은 횟수 i
	//turn을 0과 1로 바꿔가며 플레이할 유저를 지정함
	for(int i = 0 ; ; turn = (turn+1)%2, i++)
	{
		//해당 턴의 유저에게 첫번째 카드 위치를 입력 받음
		if(turn%2)
		{
			p1 = player1.inputFirst();
		}
		else
		{
			p1 = player2.inputFirst();
		}

		//p1위치에 있는 값을 두 플레이어에게 알림
		player1.checkCardInfo(p1, game.getCard(p1));
		player2.checkCardInfo(p1, game.getCard(p1));
			
		//해당 턴의 유저에게 두번째 카드 위치를 입력 받음
		if (turn % 2) {
			p2 = player1.inputSecond();
			//cout << "1->" << p1 << " " << p2 << endl;
		}
		else {
			p2 = player2.inputSecond();
			//cout <<"2->" << p1 << " " << p2 << endl;
		}

		//p2위치에 있는 값을 두 플레이어에게 알림
		player1.checkCardInfo(p2, game.getCard(p2));
		player2.checkCardInfo(p2, game.getCard(p2));

		//p1과  p2를 매칭시켜서 짝인지 확인함
		if(game.tryMatching(p1, p2))
		{
			//짝이 맞을 경우 해당 턴의 유저의 점수를 올림
			if(turn%2)
			{
				player1Score++;
				cout << "Player1 Matched) " << p1 << " and " << p2 << " are " <<  game.getCard(p1) << endl;
			}
			else
			{
				player2Score++;
				cout << "Player2 Matched) " << p1 << " and " << p2 << " are " <<  game.getCard(p1) << endl;
			}

			//짝을 모두 찾은 경우 게임 종료
			if(player1Score+player2Score >= BOARD_SIZE*BOARD_SIZE/2)
			{
				cout << "Player1 total score : " <<  player1Score << endl;
				cout << "Player2 total score : " <<  player2Score << endl;
				cout << "total turn count : " <<  i << endl;
				break;
			}

			//두 플레이어에게 p1, p2가 어떤 값으로 매칭된 건지 알려줌
			player1.matchedCard(p1, p2, game.getCard(p1));
			player2.matchedCard(p1, p2, game.getCard(p1));

			//해당 유저의 턴을 1회 더 하기위해 turn을 바꿈
			turn++;
		}
	}
}