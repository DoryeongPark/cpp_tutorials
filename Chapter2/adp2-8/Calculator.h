#pragma once

#include <iostream>

/*
*	Calculator
*	멤버변수 : a - 정수1, b - 정수2
*/
class Calculator {
protected:
	int a;
	int b;
public:
	Calculator() noexcept : a(0), b(0) {}
	//디폴트 값 a = 0, b = 0
	void setValue(const int& _a, const int& _b);
	//a와 b의 Setter	
	virtual int calculate() = 0;//순수 가상 함수
};

//Add, Sub, Mul, Div 클래스 정의
class Add : public Calculator {//클래스 Add에 Calculator를 Public 상속
public:
	int calculate();
};
class Sub : public Calculator {//클래스 Add에 Calculator를 Public 상속
public:
	int calculate();
};
class Mul : public Calculator {//클래스 Add에 Calculator를 Public 상속
public:
	int calculate();
};
class Div : public Calculator {//클래스 Add에 Calculator를 Public 상속
public:
	int calculate();
};