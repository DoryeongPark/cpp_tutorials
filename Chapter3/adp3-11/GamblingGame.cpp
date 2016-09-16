#include "GamblingGame.h"	
#include "Player.h"

//GamblingGame 클래스 정의

//인당 뽑을 카드의 개수와 카드의 종류의 수(범위)를 Set하는 생성자
GamblingGame::GamblingGame(const int& _num_of_cards, const int& _limit) noexcept{
	num_of_cards = _num_of_cards;//뽑을 카드의 개수 대입
	limit = _limit;//카드의 종류의 수 대입
}
//현재 플레이어들을 저장한 벡터를 Get한다.
std::vector<Player*>& GamblingGame::get_vector() noexcept{
	return players;
}

//카드를 현재 참가하고 있는 플레이어들에게 분배한다.
void GamblingGame::distribute_random_cards() noexcept{
	for (auto p : players) {//반복문
		for (int i = 0; i < num_of_cards; ++i)//입력한 카드의 개수만큼 분배
			p->show_cards().push_back(rand() % limit);//카드의 종류의 수만큼 랜덤하게 생성하여 분배
	}
}
//이긴 사람을 결정한다.
void GamblingGame::get_winner()noexcept {
	//뽑은 카드의 종류가 모두 같은 사람들을 저장하는 벡터
	std::vector<Player*> winner;
	//참가하고 있는 모든 Player들이 자신의 카드를 뒤집는다.
	for (auto p : players) {
		if (p->flip_cards())//자신의 카드의 종류가 모두 같을 경우
			winner.push_back(p);//winner 벡터에 넣는다.
	}

	if (winner.size() == 1) {//만약에 winner가 1명이면 
		//해당 Player가 승리했음을 알린다.
		std::cout << "승리자는 " << winner.at(0)->get_name() << "입니다. " << std::endl;
		
		for (auto p : players)//모든 Player 메모리 해제
			delete p;
		
		exit(0);//프로그램 종료
	}
	else {//아닐 경우 승부가 정해지지 않은 것이다.
		std::cout << "승부가 정해지지 않았습니다." << std::endl;
	}
}

//게임을 리셋한다.
void GamblingGame::reset_game() noexcept {
	for (auto p : players) {//참가한 Player들의 카드를 지운다.
		p->show_cards().clear();
	}
}


