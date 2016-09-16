#pragma once
#include <iostream>
#include <string>
//클래스 정의
const double M_PI = 3.141592;//원주율 상수 정의

class Circle {
	double radius;//반지름
	double area;//원 넓이
	int num;//원 번호
protected:
	static int circle_num;//클래스 변수 원 번호(생성된 원의 개수)
public:
	Circle();//생성자
	~Circle()noexcept;//소멸자
	double getArea()noexcept;//원 넓이 반환
	int getCircleNum()noexcept;//원 번호 반환
};