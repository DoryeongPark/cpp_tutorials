#include "GamblingGame.h"	
#include "Player.h"

//GamblingGame Ŭ���� ����

//�δ� ���� ī���� ������ ī���� ������ ��(����)�� Set�ϴ� ������
GamblingGame::GamblingGame(const int& _num_of_cards, const int& _limit) noexcept{
	num_of_cards = _num_of_cards;//���� ī���� ���� ����
	limit = _limit;//ī���� ������ �� ����
}
//���� �÷��̾���� ������ ���͸� Get�Ѵ�.
std::vector<Player*>& GamblingGame::get_vector() noexcept{
	return players;
}

//ī�带 ���� �����ϰ� �ִ� �÷��̾�鿡�� �й��Ѵ�.
void GamblingGame::distribute_random_cards() noexcept{
	for (auto p : players) {//�ݺ���
		for (int i = 0; i < num_of_cards; ++i)//�Է��� ī���� ������ŭ �й�
			p->show_cards().push_back(rand() % limit);//ī���� ������ ����ŭ �����ϰ� �����Ͽ� �й�
	}
}
//�̱� ����� �����Ѵ�.
void GamblingGame::get_winner()noexcept {
	//���� ī���� ������ ��� ���� ������� �����ϴ� ����
	std::vector<Player*> winner;
	//�����ϰ� �ִ� ��� Player���� �ڽ��� ī�带 �����´�.
	for (auto p : players) {
		if (p->flip_cards())//�ڽ��� ī���� ������ ��� ���� ���
			winner.push_back(p);//winner ���Ϳ� �ִ´�.
	}

	if (winner.size() == 1) {//���࿡ winner�� 1���̸� 
		//�ش� Player�� �¸������� �˸���.
		std::cout << "�¸��ڴ� " << winner.at(0)->get_name() << "�Դϴ�. " << std::endl;
		
		for (auto p : players)//��� Player �޸� ����
			delete p;
		
		exit(0);//���α׷� ����
	}
	else {//�ƴ� ��� �ºΰ� �������� ���� ���̴�.
		std::cout << "�ºΰ� �������� �ʾҽ��ϴ�." << std::endl;
	}
}

//������ �����Ѵ�.
void GamblingGame::reset_game() noexcept {
	for (auto p : players) {//������ Player���� ī�带 �����.
		p->show_cards().clear();
	}
}


