#include "Ram.h"	
using namespace std;

//Ram 클래스의 함수 정의부
Ram::Ram() noexcept :size(100 * 1024) {//size default값 100*1024
}

Ram::~Ram() noexcept {//소멸자 
	cout << "메모리 제거됨" << endl;//소멸되면서 문자 출력
}

char Ram::read(const int& address)noexcept {
	return mem[address];//매개변수 주소의 배열 원소의 값을 반환
}

void Ram::write(const int& address, const char& value) noexcept {
	mem[address] = value;//매개변수 주소의 배열원소에 매개변수 값을 대입한다.
}