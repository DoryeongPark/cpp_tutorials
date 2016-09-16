#include "Player.h"
//Player Ŭ���� ����
//������ : Player�� �̸� Set
Player::Player(const std::string& _name) noexcept {
	name = _name;
}
//���� Player�� ������ �ִ� ī�带 get�Ѵ�.
std::vector<int>& Player::show_cards() noexcept {
	return cards;
}
//���� Player�� ���ӿ� �����Ѵ�.
void Player::participates(GamblingGame& g) {	
	g.get_vector().push_back(this);//������ ���Ϳ� ���� ��ü�� �����Ѵ�.
}
//�ڽ��� ������ �ִ� ī�带 �����´�. ��� ī�� ���� ���� ��� true�� ��ȯ�Ѵ�.
bool Player::flip_cards() noexcept {

	std::string input;//�Է°�

	std::cout << name << ":<Enter>";
	std::getline(std::cin, input, '\n');//�ƹ� Ű�� �Է� �޴´�.(Enter : Filp ����)

	auto i_compare = cards.at(0);//��� ī�� ���� ������ ���ϱ� ���� �񱳰�

	for_each(cards.cbegin(), cards.cend(), [&](int a) {
		std::cout << a << " ";//������ �ִ� ī���� ������ ��� ����Ѵ�.
	});

	std::cout << std::endl;
	//��� ī�尡 �񱳰��� ������ Ȯ���Ѵ�.
	if (all_of(cards.begin(), cards.end(), [&](int i) {
		if (i_compare == i)//�񱳰��� ���� ���
			return true;
		else//�ٸ� ���
			return false;
	}))//��� ���� ���
		return true;//true ��ȯ
	else//�ϳ� �̻� �ٸ� ���
		return false;//false ��ȯ
}
//���� Player�� �̸��� ��ȯ�Ѵ�.
std::string Player::get_name() noexcept{
	return name;
}
