#include "Calculator.h"

using namespace std;

//Calculator 클래스의 setValue 함수 정의
//매개변수 : a - 정수1 / b - 정수2
void Calculator::setValue(const int& _a, const int& _b) {
	a = _a; b = _b;//정수1과 정수2값 매개변수로 받아 대입
}

int Add::calculate() { return a + b; }
//Add 클래스의 calculate함수 정의(두 정수의 덧셈값 반환)
int Sub::calculate() { return a - b; }
//Add 클래스의 calculate함수 정의(두 정수의 덧셈값 반환)
int Mul::calculate() { return a * b; }
//Add 클래스의 calculate함수 정의(두 정수의 덧셈값 반환)
int Div::calculate() { return a / b; }
//Add 클래스의 calculate함수 정의(두 정수의 덧셈값 반환)

int main() {
	Add a; Sub s; Mul m; Div d;
	//Add 객체 a, Sub 객체 s, Mul 객체 m, Div 객체 d를 생성
	int value1, value2;//정수형 변수 2개 선언
	char oper;//연산자를 위한 변수 선언

	for (;;) {
		cout << "두 정수와 연산자를 입력하세요 >>";
		cin >> value1 >> value2 >> oper;
		//정수1, 정수2, 연산자를 입력받는다.
		if (oper == '+') {//연산자가 +인 경우
			a.setValue(value1, value2);//입력한 정수들로 Add객체에 Set
			cout << a.calculate() << endl;//계산한 값 출력
		}
		else if (oper == '-') {//연산자가 -인 경우
			s.setValue(value1, value2);//입력한 정수들로 Sub객체에 Set
			cout << s.calculate() << endl;//계산한 값 출력
		}
		else if (oper == '*') {//연산자가 *인 경우
			m.setValue(value1, value2);//입력한 정수들로 Mul객체에 Set
			cout << m.calculate() << endl;//계산한 값 출력
		}
		else if (oper == '/') {//연산자가 /인 경우
			d.setValue(value1, value2);//입력한 정수들로 Div객체에 Set
			cout << d.calculate() << endl;//계산한 값 출력
		}
		else {//연산자가 나머지인 경우
			cout << "default" << endl;
		}
	}
}