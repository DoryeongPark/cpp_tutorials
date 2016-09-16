#include <iostream>

using namespace std;

/*
*	Oval
*	멤버변수 : width - 가로 / height - 높이
*	설명 : 타원을 추상화한 클래스
*/
class Oval {
private:
	int width;
	int height;

public:
	Oval()noexcept : width(1), height(1) {} //디폴트 생성자 초기값 width = 1, height = 1
											//정수형 매개변수 2개(width, height)를 받는 생성자
	Oval(const int& _width, const int& _height)noexcept {
		width = _width;
		height = _height;
	}
	//소멸자 - 현재의 원소 정보를 출력하고 객체가 소멸된다.
	~Oval() { cout << "Oval 소멸 : width = " << width << ", height = " << height << endl; }
	int getWidth()noexcept { return width; }	// 가로 반환
	int getHeight()noexcept { return height; } // 높이 반환
	void set(const int& w, const int& h)noexcept { width = w; height = h; }//가로와 높이의 값을 set한다
	void show()noexcept {//가로와 높이의 값 출력
		cout << "width = " << width << " height = " << height << endl;
	}
};

int main() {
	Oval a, b{ 3, 4 };//Oval객체 a 생성, width = 3, height = 4인 Oval객체 b 생성
	a.set(10, 20);//객체 a의 width = 10, height = 20로 set한다.
	a.show();//a의 정보 출력
	cout << b.getWidth() << ", " << b.getHeight() << endl;//b의 가로와 높이 정보 따로 출력
}