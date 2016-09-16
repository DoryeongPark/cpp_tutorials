#pragma once

#include <iostream>

//Ram 클래스 선언부 
class Ram
{
	char mem[100 * 1024] = { 0, };//메모리를 표현한 배열, 원소 0으로 모두 초기화
	int size;
public:
	Ram() noexcept;//생성자
	~Ram() noexcept;//소멸자
	char read(const int& address) noexcept;//메모리 주소에 있는 값 반환
	void write(const int& address, const char& value) noexcept;//해당 메모리 주소에 해당 값을 삽입
};
