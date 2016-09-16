#include "Box.h"	

using namespace std;

//Box 클래스 함수 정의부 

Box::Box(int w, int h) {
	setSize(w, h);//w와 h값 매개변수로 받아서 대입
	fill = 'x';//박스를 x로 채운다.
}

void Box::setFill(char f) {
	fill = f;//채움문자를 set한다.
}

void Box::setSize(int w, int h) {//가로와 높이를 set한다.
	width = w;
	height = h;
}

void Box::draw() {//가로와 높이만큼 채움문자로 채운다.
	for (int n = 0; n < height; n++) {//설정된 높이만큼 반복문 실행
		for (int m = 0; m< width; m++) {//설정된 가로만큼 반복문 실행
			cout << fill;//채움문자 출력
		}
		cout << endl;
	}
}