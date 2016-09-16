#include "GameManager.h"
GameManager::GameManager()
{
	//�޴����� �����ɶ� ���ھ� �ʱ�ȭ
	player1Score = 0;
	player2Score = 0;
}
void GameManager::play()
{
	Point p1, p2;
	
	//������ �÷��̾ �������� ����
	int turn = rand()%2;

	if(turn%2)
		cout << "Player1 Start" << endl;
	else
		cout << "Player2 Start" << endl;

	//�� ī�带 ������ Ƚ�� i
	//turn�� 0�� 1�� �ٲ㰡�� �÷����� ������ ������
	for(int i = 0 ; ; turn = (turn+1)%2, i++)
	{
		//�ش� ���� �������� ù��° ī�� ��ġ�� �Է� ����
		if(turn%2)
		{
			p1 = player1.inputFirst();
		}
		else
		{
			p1 = player2.inputFirst();
		}

		//p1��ġ�� �ִ� ���� �� �÷��̾�� �˸�
		player1.checkCardInfo(p1, game.getCard(p1));
		player2.checkCardInfo(p1, game.getCard(p1));
			
		//�ش� ���� �������� �ι�° ī�� ��ġ�� �Է� ����
		if (turn % 2) {
			p2 = player1.inputSecond();
			//cout << "1->" << p1 << " " << p2 << endl;
		}
		else {
			p2 = player2.inputSecond();
			//cout <<"2->" << p1 << " " << p2 << endl;
		}

		//p2��ġ�� �ִ� ���� �� �÷��̾�� �˸�
		player1.checkCardInfo(p2, game.getCard(p2));
		player2.checkCardInfo(p2, game.getCard(p2));

		//p1��  p2�� ��Ī���Ѽ� ¦���� Ȯ����
		if(game.tryMatching(p1, p2))
		{
			//¦�� ���� ��� �ش� ���� ������ ������ �ø�
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

			//¦�� ��� ã�� ��� ���� ����
			if(player1Score+player2Score >= BOARD_SIZE*BOARD_SIZE/2)
			{
				cout << "Player1 total score : " <<  player1Score << endl;
				cout << "Player2 total score : " <<  player2Score << endl;
				cout << "total turn count : " <<  i << endl;
				break;
			}

			//�� �÷��̾�� p1, p2�� � ������ ��Ī�� ���� �˷���
			player1.matchedCard(p1, p2, game.getCard(p1));
			player2.matchedCard(p1, p2, game.getCard(p1));

			//�ش� ������ ���� 1ȸ �� �ϱ����� turn�� �ٲ�
			turn++;
		}
	}
}