#pragma once

#include "myheader.h"

class Player;//Player 클래스를 참조하기 위한 선언
//GamblingGame 클래스 선언
class GamblingGame {
	std::vector<Player*> players;//게임에 참가한 Players
	int num_of_cards;//게임에 사용하는 인당 카드의 수
	int limit;//카드 종류의 수 ex) limit = 3일 경우 카드의 종류 : 0 ~ 2
public:
	GamblingGame() = default;//기본 생성자
	GamblingGame(const int& _num_of_cards, const int& _limit) noexcept;//인당 카드의 수, 카드 종류의 수를 Set하는 생성자
	std::vector<Player*>& get_vector()noexcept;//현재 플레이어들의 getter
	void distribute_random_cards()noexcept;//게임에 참가하고 있는 모든 플레이어들에게 카드 배포
	void get_winner()noexcept;//승자를 가린다.
	void reset_game()noexcept;//게임을 reset한다.
};