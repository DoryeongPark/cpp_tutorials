#include "Common.h"
#include "GameManager.h"
GameManager::GameManager()
{
	//보드가 생성될때 스코어 초기화
	player1Score = 0;
	player2Score = 0;
}
void GameManager::play()
{
	Point p;

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
		//해당 턴의 유저에게 입력을 받음
		if(turn%2)
		{
			p = player1.input();
		}
		else
		{
			p = player2.input();
		}

		//해당 좌표의 값을 확인함
		int value = game.getBoardInfo(p);

		//지뢰일 경우
		if(value == -1)
		{
			//이미 확인한 지뢰가 아닐 경우
			if(game.checkOpend(p) == false)
			{
				//해당 지뢰는 이미 찾았다고 표시
				game.setOpend(p);

				//해당 플레이어의 점수를 올림
				if(turn%2)
				{
					player1Score++;
					cout << "Player1 Find mine) " << p << endl;
				}
				else
				{
					player2Score++;
					cout << "Player2 Find mine) " << p << endl;
				}
			}

			//폭탄을 모두 찾은 경우 스코어 내용을 출력하고 종료함
			if(player1Score+player2Score >= MINE_COUNT)
			{
				cout << "Player1 total score : " <<  player1Score << endl;
				cout << "Player2 total score : " <<  player2Score << endl;
				cout << "total turn count : " <<  i << endl;
				break;
			}

			//폭탄의 위치를 두 플레이어에게 알림
			player1.checkMineInfo(p);
			player2.checkMineInfo(p);

			//해당 유저의 턴을 1회 더 하기위해 turn을 바꿈
			turn++;
		}
		//지뢰가 아닐 경우
		else
		{
			//이번 턴의 좌표에 어떤 값이 있었는지 알림
			player1.checkBoardInfo(p, value);
			player2.checkBoardInfo(p, value);
		}
	}

}