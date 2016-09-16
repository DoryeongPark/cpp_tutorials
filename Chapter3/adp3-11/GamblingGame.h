#pragma once

#include "myheader.h"

class Player;//Player Ŭ������ �����ϱ� ���� ����
//GamblingGame Ŭ���� ����
class GamblingGame {
	std::vector<Player*> players;//���ӿ� ������ Players
	int num_of_cards;//���ӿ� ����ϴ� �δ� ī���� ��
	int limit;//ī�� ������ �� ex) limit = 3�� ��� ī���� ���� : 0 ~ 2
public:
	GamblingGame() = default;//�⺻ ������
	GamblingGame(const int& _num_of_cards, const int& _limit) noexcept;//�δ� ī���� ��, ī�� ������ ���� Set�ϴ� ������
	std::vector<Player*>& get_vector()noexcept;//���� �÷��̾���� getter
	void distribute_random_cards()noexcept;//���ӿ� �����ϰ� �ִ� ��� �÷��̾�鿡�� ī�� ����
	void get_winner()noexcept;//���ڸ� ������.
	void reset_game()noexcept;//������ reset�Ѵ�.
};