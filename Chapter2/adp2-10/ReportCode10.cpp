#include "Ram.h"

using namespace std;

int main() {
	Ram ram;//Ram 클래스 객체 생성
	ram.write(100, 20);//주소 100에 값 20 삽입
	ram.write(101, 30);//주소 101에 값 30 삽입
	auto res = ram.read(100) + ram.read(101);
	//주소 100의 값과 주소 101의 값을 더해서 변수 res에 대입
	ram.write(102, res);//변수 res를 주소 102에 삽입
	cout << "102번지의 값 = " << (int)ram.read(102) << endl;
	//주소 102에 있는 값 출력
}