#pragma once
#include "Box.h"

using namespace std;

int main() {
	Box b{ 10 , 2 };//가로 10, 세로 2의 박스 객체 생성
	b.draw();//박스영역을 그린다
	cout << endl;
	b.setSize(7, 4);//가로 7, 세로 4로 변경
	b.setFill('^');//채움문자 ^로 변경
	b.draw();//박스영역을 그린다
}