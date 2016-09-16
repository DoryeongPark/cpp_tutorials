#pragma once

#include <iostream>

/*
*	Calculator
*	������� : a - ����1, b - ����2
*/
class Calculator {
protected:
	int a;
	int b;
public:
	Calculator() noexcept : a(0), b(0) {}
	//����Ʈ �� a = 0, b = 0
	void setValue(const int& _a, const int& _b);
	//a�� b�� Setter	
	virtual int calculate() = 0;//���� ���� �Լ�
};

//Add, Sub, Mul, Div Ŭ���� ����
class Add : public Calculator {//Ŭ���� Add�� Calculator�� Public ���
public:
	int calculate();
};
class Sub : public Calculator {//Ŭ���� Add�� Calculator�� Public ���
public:
	int calculate();
};
class Mul : public Calculator {//Ŭ���� Add�� Calculator�� Public ���
public:
	int calculate();
};
class Div : public Calculator {//Ŭ���� Add�� Calculator�� Public ���
public:
	int calculate();
};