#pragma once
#include <iostream>	
#include <string>

//클래스 Box 구현
class Box {
private:
	int width;//가로
	int height;//높이
	char fill;//채움문자
public:
	Box(int w, int h);//생성자
	void setFill(char f);//채우기 함수
	void setSize(int w, int h);//가로 높이 Setter
	void draw();//그림
};