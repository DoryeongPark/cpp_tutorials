#include <iostream>	

using namespace std;

/*
*	Tower
*	멤버변수 : height - 타워의 높이
*	설명 : 타워를 추상화한 클래스
*/
class Tower {
private:
	int height;
public:
	Tower() noexcept : height(1) {} //디폴트 생성자 - 높이의 초기값 : 1
	Tower(const int& _height) noexcept { height = _height; }//생성자 - 매개변수로 높이 초기화
	int getHeight() noexcept {//객체가 가지고 있는 현재 높이 반환
		return height;
	}
};

int main() {
	Tower myTower;//탑 객체 생성(높이 : 1)
	Tower seoulTower{ 100 };//높이가 100인 탑 객체 생성

	cout << "높이는 " << myTower.getHeight() << "미터" << endl;//첫 번째 생성한 높이값 출력
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;//두 번째 생성한 높이값 출력

}