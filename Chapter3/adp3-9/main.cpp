#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
#include <stack>

const double M_PI = 3.141592; //원주율 상수 정의

using namespace std;

/*
*	Circle
*	설명 : 원을 추상화한 클래스
*/
class Circle {
	double radius;//반지름
	double area;//원 면적
	string name;//원 이름
	int num;//원 번호

protected:
	static int circle_num;//할당할 원 번호
public:
	//기본 생성자
	Circle() {
		num = ++circle_num;//원 번호를 할당한다.

		for (;;) {//입력한 정보가 입력포맷과 부합할 때까지 무한루프
			
			cout << "원 " << num << " 의 이름과 반지름 >> ";

			string input;//입력 문자열

			getline(cin, input, '\n');//문자 입력

			name = input.substr(0, input.find(' ', 0));//첫 번째 문자열 추출하여 이름에 대입
			auto s_radius = input.substr(input.find(' ', 0) + 1, 
				(input.find(' ', input.find(' ', 0) + 1)) - 
				(input.find(' ', 0) + 1));//두 번째 문자열 추출

			//추출한 두 번째 문자열이 변환 조건을 만족할 경우
			if (all_of(s_radius.begin(), s_radius.end(), [&](char c)->bool{
				if (isdigit(c) || c == '.')
					return true;
				else
					return false;
			})) {
				radius = stod(s_radius);//변환하여 멤버변수에 대입
				area = radius * radius * M_PI;//원의 넓이를 계산하여 멤버변수에 대입
				break;
			}//만약 추출한 두 번째 문자열이 숫자와 .를 제외한 이외의 문자를 가질 경우
			else {
				cout << "숫자를 입력해 주세요." << endl;
			}
		}
	}
	//원 면적의 Getter
	double getArea() noexcept {
		return area;
	}
	//원 이름의 Getter
	string getName() noexcept {
		return name;
	}
};

int Circle::circle_num = 0; //클래스 변수 초기화

/*
*	CircleManager
*	설명 : 원들을 관리하는 클래스
*/
class CircleManager {
private:
	vector<Circle*> circle_arr;//원들의 포인터를 저장할 벡터
public:
	//입력한 사이즈만큼 벡터에 미리 할당
	CircleManager(const int& size) {
		circle_arr.reserve(size);
	}
	//매개변수와 일치하는 이름의 원의 면적을 출력한다.
	void searchByName(const string& name) noexcept {
		for (auto c : circle_arr) {//반복문
			if (c->getName() == name)//만약 매개변수와 해당 원의 이름과 일치할 경우
				cout << c->getName() << "의 면적은 " << c->getArea() << endl;//해당 원의 면적 출력
		}
	}
	//매개변수보다 큰 원의 면적을 출력한다.
	void searchByArea(const double& limit_lower) noexcept{

		cout << limit_lower << "보다 큰 원을 검사합니다." << endl;
		for_each(circle_arr.begin(), circle_arr.end(), [&](Circle* c) {//반복문
			if (c->getArea() > limit_lower)//원의 면적이 매개변수보다 클 경우
				cout << c->getName() << "의 면적은 " << c->getArea() << endl;//해당 원의 면적 출력
		});
	}
	//매개변수 원을 벡터에 저장한다.
	void storeCircle(Circle* c) {
		circle_arr.push_back(c);
	}
	//벡터를 노출한다.
	vector<Circle*> getVec() noexcept {
		return circle_arr;
	}
};

int main() {

	int num_of_circles;//원의 개수

	cout << "원의 개수 >> ";

	//원의 개수 입력, 숫자를 입력하지 않았을 경우
	while (!(cin >> num_of_circles)) {
		cin.clear();//버퍼를 비운다.

		while (cin.get() != '\n')//개행 문자를 지운다.
			continue;

		cout << "숫자를 입력하세요." << endl;//문구 출력
		cout << "원의 개수 >> ";
	}

	cin.ignore();//다음 입력에 영향을 주지 않도록 설정
	//입력한 개수만큼 설정된 CircleManager 객체 생성
	CircleManager cm{ num_of_circles };
	
	//입력한 개수만큼 원을 생성한다. 생성과 동시에 매니저가 관리한다.
	for (int i = 0; i < num_of_circles; ++i) 
		cm.storeCircle(new Circle{});
	
	string name_search;//원의 이름

	cout << "검색하고자 하는 원의 이름 >> ";
	//원의 이름 입력
	getline(cin, name_search, '\n');
	//입력한 원의 이름과 일치하는 원 면적 출력
	cm.searchByName(name_search);

	double area_search;

	cout << "최소 면적을 수로 입력하세요 >> ";
	//원의 최소 면적 입력, 숫자를 입력하지 않았을 경우
	while (!(cin >> area_search)) {
		cin.clear();//버퍼를 비운다.

		while (cin.get() != '\n')//개행문자를 지운다.
			continue;

		cout << "정수를 입력하세요." << endl;//문구 출력
		cout << "최소 면적을 정수로 입력하세요 >> " << endl;
	}
	//입력한 최소 면적보다 큰 원들의 면적을 출력한다.
	cm.searchByArea(area_search);

	//벡터의 원소 메모리 모두 해제
	for (auto c : cm.getVec()) 
		delete c;
	
}