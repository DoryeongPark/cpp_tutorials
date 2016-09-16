#include <iostream>	
#include <string>

using namespace std;

/*
*	Integer
*	멤버변수 : i - 정수
*	설명 : 정수를 추상화한 클래스
*/
class Integer {
private:
	int i;
public:
	Integer() noexcept : i(0) {}
	//디폴트 생성자 i의 값을 0으로 초기화한다.
	Integer(const int& _i) noexcept { i = _i; }
	//매개변수가 하나의 정수인 생성자(매개변수 대입)
	Integer(const string& _s) noexcept { i = stoi(_s); }
	//매개변수가 하나의 문자열인 생성자(정술 변환한 뒤 대입)
	int get() noexcept { return i; }
	//현재 정수를 반환한다.
	void set(const int& _i)noexcept { i = _i; }
	//현재의 정수를 매개변수로 다시 set한다.
	bool isEven() noexcept {//현재의 정수가 짝수인지 아닌지 진리값 반환
		if (!(i % 2))
			return true;//짝수일 경우 true 반환
		else
			return false;//홀수일 경우 false 반환
	}
};

int main() {
	Integer n{ 30 };//정수 30 Integer 객체 n 생성
	cout << n.get() << ' ';//내용 출력
	n.set(50);//객체 n의 내용 50으로 set
	cout << n.get() << ' ';//내용 출력

	Integer m{ "300" };//문자열 300을 매개변수로 Integer 객체 m 생성
	cout << m.get() << ' ';//내용 출력
	cout << m.isEven() << endl;//m이 가진 정수가 홀수인지 짝수인지 진리값 출력
}