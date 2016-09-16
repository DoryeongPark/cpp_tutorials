#include "Player.h"
//Player 클래스 정의
//생성자 : Player의 이름 Set
Player::Player(const std::string& _name) noexcept {
	name = _name;
}
//현재 Player가 가지고 있는 카드를 get한다.
std::vector<int>& Player::show_cards() noexcept {
	return cards;
}
//현재 Player가 게임에 참가한다.
void Player::participates(GamblingGame& g) {	
	g.get_vector().push_back(this);//게임의 벡터에 현재 객체를 저장한다.
}
//자신이 가지고 있는 카드를 뒤집는다. 모든 카드 값이 같을 경우 true를 반환한다.
bool Player::flip_cards() noexcept {

	std::string input;//입력값

	std::cout << name << ":<Enter>";
	std::getline(std::cin, input, '\n');//아무 키나 입력 받는다.(Enter : Filp 실행)

	auto i_compare = cards.at(0);//모든 카드 값이 같은지 비교하기 위한 비교값

	for_each(cards.cbegin(), cards.cend(), [&](int a) {
		std::cout << a << " ";//가지고 있는 카드의 내용을 모두 출력한다.
	});

	std::cout << std::endl;
	//모든 카드가 비교값과 같은지 확인한다.
	if (all_of(cards.begin(), cards.end(), [&](int i) {
		if (i_compare == i)//비교값과 같을 경우
			return true;
		else//다를 경우
			return false;
	}))//모두 같을 경우
		return true;//true 반환
	else//하나 이상 다를 경우
		return false;//false 반환
}
//현재 Player의 이름을 반환한다.
std::string Player::get_name() noexcept{
	return name;
}
