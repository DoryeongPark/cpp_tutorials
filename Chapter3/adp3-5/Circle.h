#pragma once
#include <iostream>
#include <string>
//Ŭ���� ����
const double M_PI = 3.141592;//������ ��� ����

class Circle {
	double radius;//������
	double area;//�� ����
	int num;//�� ��ȣ
protected:
	static int circle_num;//Ŭ���� ���� �� ��ȣ(������ ���� ����)
public:
	Circle();//������
	~Circle()noexcept;//�Ҹ���
	double getArea()noexcept;//�� ���� ��ȯ
	int getCircleNum()noexcept;//�� ��ȣ ��ȯ
};