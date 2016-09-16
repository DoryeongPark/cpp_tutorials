#include "Player.h"	
#include "GamblingGame.h"

using namespace std;
//�߰� : ������ �������� �� / �δ� ����� ī���� ���� / ī�� ������ ���� Setting ����
int main() {
	
	srand((unsigned int)time(NULL));//�õ尪 

	int num_of_players;//������ �������� ��
	int num_of_cards;//�δ� ����� ī���� ����
	int limit;//ī���� ������ ��

	cout << "���ӿ� ������ �������� ���� �Է��ϼ���. >> ";
	cin >> num_of_players;//������ �������� �� �Է�

	cout << "���ӿ� ����� ī���� ������ �Է��ϼ���. >> ";
	cin >> num_of_cards;//�δ� ����� ī���� ���� �Է�

	cout << "ī���� ������ ���� �Է��ϼ���. >> ";
	cin >> limit;//ī���� ������ �� �Է�
	//�Է��� �ɼǸ�ŭ ���� ����
	GamblingGame gg{ num_of_cards, limit };
	//�Է��� �ɼǸ�ŭ ���� ����
	for (int i = 0; i < num_of_players; ++i) {
		string input;//���� �̸�
		cout << i + 1 << "��° ���� �̸� >> ";
		cin >> input;//���� �̸� �Է�
		auto p = new Player{ input };//�ش� �̸��� �÷��̾� ����
		p->participates(gg);//�ش� �÷��̾ ���ӿ� ����
	}

	std::cin.ignore();//�Է� ������ ������ ��� �����Ͽ� ������.
	
	for (;;) {
		gg.distribute_random_cards();//������ �����ڵ鿡�� ī�带 �����Ѵ�.
		gg.get_winner();//���ڸ� ������.
		gg.reset_game();//������ �����Ѵ�.
	}
	
}