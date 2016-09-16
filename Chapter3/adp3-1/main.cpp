#include <iostream>

using namespace std;

/*
*	Color 
*	색깔을 나타내는 RGB 값을 추상화한 클래스
*/
class Color {
private:
	int red;//R channel
	int green;//G channel
	int blue;//B channel
public:
	//멤버 변수들의 default값 설정
	Color() noexcept : red(0), green(0), blue(0) {}

	//정수를 매개변수로 하는 생성자(0 : Red, 1 : Green, 2 : Blue)
	Color(const int& channel) {
		if (channel == 0) {//매개변수 0일 경우
			red = 255; green = 0; blue = 0;
		}
		else if (channel == 1) {//매개변수 1일 경우
			red = 0; green = 255; blue = 0;
		}
		else if (channel == 2){//매개변수 나머지일 경우
			red = 0; green = 0; blue = 255;
		}
		else {
			red = 0; green = 0; blue = 0;
		}
			
	}
	//RGB 각각의 값을 매개변수로 받는 생성자
	Color(const int& r, const int& g, const int& b) noexcept {
		red = r;
		green = g;
		blue = b;
	}

	~Color() = default;//default 소멸자
	//현재 객체의 RGB값을 매개변수로 set한다.
	void setColor(const int& r, const int& g, const int& b) noexcept {
		red = r;
		green = g;
		blue = b;
	}
	//현재 멤버변수들의 내용을 콘솔창에 출력
	void show() noexcept {
		cout << red << ' ' << green << ' ' << blue << endl;
	}

};

int main() {

	Color screenColor{ 255, 0, 0 };
	Color *p;

	//1. p가 screenColor의 주소를 가지도록 코드 작성
	p = &screenColor;

	//2. p와 show()를 이용하여 screenColor 색 출력
	p->show();

	//3. Color의 일차원 배열 colors 선언, 원소는 3개
	Color* colors = new Color[3];
	
	//4. p가 colors 배열을 가리키도록 코드 작성
	p = colors;

	//5. p와 setColor를 이용하여 colors[0], colors[1], colors[2]가
	//각각 빨강 초록 파랑색을 가지도록 코드 작성
	for (int i = 0; i < 3; ++i)
		i[colors] = Color{ i };

	//6. show()를 이용하여 colors 배열의 모든 객체의색 출력 for문 사용
	for (int i = 0; i < 3; ++i)
		colors[i].show();

	delete[] colors;//메모리 해제
}