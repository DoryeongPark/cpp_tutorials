#include <iostream>	
#include <string>
#include <vector>
#include <algorithm>

const double M_PI = 3.141592; //원주율 상수 선언

using namespace std;

/*
*	Circle
*	설명 : 원을 추상화한 클래스
*	추가 : 모든 입력 예외처리
*/
class Circle {
private:
	double radius; //반지름
	double area; //원 넓이
	int num; //원 번호

protected:
	static int circle_number;//클래스 변수 원 번호(할당용)

public:
	//객체 생성과 동시에 원 정보 입력
	Circle() noexcept{

		num = ++circle_number;//원 번호 할당 및 증가

		cout << "원 " << num << "의 반지름 >> ";
		//변수를 입력받는다. 만약 숫자 이외의 값이 버퍼에 들어갔을 경우
		while (!(cin >> radius))
		{	
			cin.clear();//버퍼를 비워주고

			while (cin.get() != '\n')//개행문자를 지워준다.
				continue;
			
			cout << "숫자를 입력하세요." << endl;//알림 문구
			cout << "원 " << num << "의 반지름 >> ";
		}

		area = M_PI * radius * radius;//원의 넓이를 계산하여 멤버변수 대입
	}
	~Circle() noexcept{
		circle_number--;//객체 소멸시 할당용 변수 감소
	}
	//원 넓이 반환
	double getArea() noexcept {
		return area;
	}
	//원 번호 반환
	int getCircleNum() noexcept {
		return num;
	}
};

int Circle::circle_number = 0;//클래스 변수 초기화

int main() {

	int arr_size;//입력할 배열 사이즈

	cout << "원의 개수 >> ";
	//변수를 입력받는다. 만약 숫자 이외의 값이 버퍼에 들어갔을 경우
	while (!(cin >> arr_size)) {
		cin.clear();//버퍼를 비운다.

		while (cin.get() != '\n')//개행문자를 지워준다.
			continue;

		cout << "숫자를 입력하세요." << endl;//알림 문구
		cout << "원의 개수 >>" << endl;
	}

	Circle* c_arr = new Circle[arr_size];//Circle객체 배열 생성
	vector<Circle> v;//Circle형 벡터 생성
	//면적이 100보다 큰 원을 벡터에 넣는다.
	for (int i = 0; i < arr_size; i++) {
		if (i[c_arr].getArea() > 100)
			v.push_back(i[c_arr]);
	}
	//면적이 100보다 큰 원의 개수 출력
	cout << "면적이 100보다 큰 원은 " << v.size() << "개 입니다." << endl;
	//면적이 100보다 큰 원들의 정보 출력
	for_each(v.cbegin(), v.cend(), [&](Circle c) {
		cout << "원 " << c.getCircleNum() << " : " << c.getArea() << endl;
	});

	delete[] c_arr;	//메모리를 동적 할당한 배열 소멸
}