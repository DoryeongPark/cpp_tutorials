#pragma once
//클래스를 참조하기 위해 헤더파일 include
#include "GamblingGame.h"
//Player 클래스 선언
class Player {
	std::string name;//Player 이름
	std::vector<int> cards;//소유하고 있는 카드
public:
	Player() = default; //기본 생성자
	Player(const std::string& _name) noexcept;//플레이어의 이름을 set하는 생성자
	std::vector<int>& show_cards() noexcept;//해당 플레이어의 카드의 getter
	void participates(GamblingGame& g);//해당 게임에 참여
	bool flip_cards() noexcept;//소유하고 있는 카드를 뒤집는다.
	std::string get_name() noexcept;//이름을 반환한다.
};