#include <iostream>	

using namespace std;

class Circle {
	int radius;
public:
	Circle() :radius(0) {}//기본 생성자 radius = 0
	//매개변수로 반지름을 set하는 생성자
	Circle(const int& r) noexcept { radius = r; }
	//복사 생성자(반지름 복사)
	Circle(const Circle& b) { radius = b.radius; }
	//반지름 Getter
	int getRadius() noexcept { return radius; }
	//반지름 Setter
	void setRadius(const int& r) { radius = r; }
	//반지름 출력
	void show() noexcept {
		cout << "반지름이 " << radius << " 인 원" << endl;
	}
	//연산자 오버로딩 구현 : 두 원의 반지름을 더한다.
	Circle operator+(Circle& b) noexcept {
		return Circle(radius + b.getRadius());//두 반지름이 더해진 객체 반환
	}
};

void main() {

	auto increaseBy = [&](Circle& a, Circle& b) {
		a = a + b;//객체 a에 b를 더한다.
	};

	Circle x{ 10 }, y{ 5 };//반지름 10, 5인 원 각각 생성
	increaseBy(x, y);//원 객체 x에 y를 더한다.
	x.show();//x의 반지름 출력
}