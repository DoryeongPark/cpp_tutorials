#include "Circle.h"

using namespace std;
//Circle 클래스 멤버 정의
int Circle::circle_num = 1;//클래스 변수 초기화

Circle::Circle() {

	num = circle_num++;//생성 순서대로 원 번호 할당 및 증가

	cout << "원 " << num << "의 반지름 >> ";

	string input;//입력받을 문자열

	try {//예외 검사
		getline(cin, input, '\n');//문자열을 입력받는다.

		for (auto c : input) {//문자 하나씩 검사
			if (!(isdigit(c) || c == '.'))//문자가 숫자 또는 .이 아닐 경우
				throw input;//예외를 처리한다.
		}
	}
	catch (...) {//예외 처리 구문
		cout << " 숫자가 아닙니다." << endl;
		exit(0);//문구 입력 및 종료
	}

	radius = stod(input);//입력받은 문자열을 double형으로 변환
	area = M_PI * radius * radius;//원 넓이를 계산하여 멤버변수로 대입
}

Circle::~Circle() noexcept {
	circle_num--;//소멸할 때 클래스 변수 감소
}
//원 넓이 반환
double Circle::getArea() noexcept {
	return area;
}
//원 번호 반환
int Circle::getCircleNum() noexcept {
	return num;
}

