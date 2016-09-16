#include <iostream>

using namespace std;

/*
*	Circle
*	설명 : 원을 추상화한 클래스
*/
class Circle {
	int radius;//반지름
public:
	Circle() = default;//생성자
	Circle(const int& _radius) noexcept : radius(_radius) {}//반지름을 매개변수로 하는 생성자
	Circle(Circle& a) noexcept{//복사 생성자
		radius = a.radius;//반지름 복사
	}
	int get_radius() noexcept{ return radius; }	//반지름 Getter
	//반지름 Setter
	void set_radius(const int& _radius) noexcept { radius = _radius; }
	void swap(Circle& c) noexcept{//현재의 원과 매개변수 원의 내용을 스왑한다.
		Circle temp = *this;//자신을 임시 변수에 저장(깊은 복사)
		*this = c;//자신에 c의 내용 저장
		c = temp;//temp에 저장했던 자신의 상태 c에 저장
	}
};

int main() {

	Circle a{ 1 };//반지름 1 Circle 객체 생성
	Circle b{ 2 };//반지름 2 Circle 객체 생성

	cout << "Before Swap" << endl;
	cout << "a : " << a.get_radius() << endl;//현재 a의 반지름 
	cout << "b : " << b.get_radius() << endl;//현재 b의 반지름

	a.swap(b);//a와 b 스왑
	cout << endl;

	cout << "After Swap" << endl;
	cout << "a : " << a.get_radius() << endl;//현재 a의 반지름
	cout << "b : " << b.get_radius() << endl;//현재 b의 반지름

}