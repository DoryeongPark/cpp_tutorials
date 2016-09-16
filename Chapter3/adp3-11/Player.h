#pragma once
//Ŭ������ �����ϱ� ���� ������� include
#include "GamblingGame.h"
//Player Ŭ���� ����
class Player {
	std::string name;//Player �̸�
	std::vector<int> cards;//�����ϰ� �ִ� ī��
public:
	Player() = default; //�⺻ ������
	Player(const std::string& _name) noexcept;//�÷��̾��� �̸��� set�ϴ� ������
	std::vector<int>& show_cards() noexcept;//�ش� �÷��̾��� ī���� getter
	void participates(GamblingGame& g);//�ش� ���ӿ� ����
	bool flip_cards() noexcept;//�����ϰ� �ִ� ī�带 �����´�.
	std::string get_name() noexcept;//�̸��� ��ȯ�Ѵ�.
};