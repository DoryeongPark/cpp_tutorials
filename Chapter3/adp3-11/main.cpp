#include "Player.h"	
#include "GamblingGame.h"

using namespace std;
//추가 : 참가할 선수들의 수 / 인당 사용할 카드의 개수 / 카드 종류의 수를 Setting 가능
int main() {
	
	srand((unsigned int)time(NULL));//시드값 

	int num_of_players;//참가할 선수들의 수
	int num_of_cards;//인당 사용할 카드의 개수
	int limit;//카드의 종류의 수

	cout << "게임에 참가할 선수들의 수를 입력하세요. >> ";
	cin >> num_of_players;//참가할 선수들의 수 입력

	cout << "게임에 사용할 카드의 개수를 입력하세요. >> ";
	cin >> num_of_cards;//인당 사용할 카드의 개수 입력

	cout << "카드의 종류의 수를 입력하세요. >> ";
	cin >> limit;//카드의 종류의 수 입력
	//입력한 옵션만큼 게임 생성
	GamblingGame gg{ num_of_cards, limit };
	//입력한 옵션만큼 선수 생성
	for (int i = 0; i < num_of_players; ++i) {
		string input;//선수 이름
		cout << i + 1 << "번째 선수 이름 >> ";
		cin >> input;//선수 이름 입력
		auto p = new Player{ input };//해당 이름의 플레이어 생성
		p->participates(gg);//해당 플레이어가 게임에 참가
	}

	std::cin.ignore();//입력 버퍼의 내용을 모두 추출하여 버린다.
	
	for (;;) {
		gg.distribute_random_cards();//게임의 참가자들에게 카드를 배포한다.
		gg.get_winner();//승자를 가린다.
		gg.reset_game();//게임을 리셋한다.
	}
	
}