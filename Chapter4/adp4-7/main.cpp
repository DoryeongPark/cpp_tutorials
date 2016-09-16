#include <iostream>	

using namespace std;

/*
*	Accumulator
*	설명 : 수를 누적할 수 있는 클래스
*/
class Accumulator {
	int value;//현재 value

public:
	Accumulator() = default;//기본 생성자(default)

	//매개변수로 value를 set하는 생성자
	explicit Accumulator(const int& value) noexcept{
		this->value = value;
	}
	
	//현재 value에 매개변수 추가
	Accumulator& add(const int& n) noexcept{
		value += n;
		return *this;//자신 반환
	}

	int get() noexcept { return value; }//value getter	
};
int main() {
	Accumulator acc{ 10 };//value 10을 가지고 있는 객체 생성

	cout << acc.add(5).add(6).add(7).get() << endl;//10 + 5 + 6 + 7 = 28
}