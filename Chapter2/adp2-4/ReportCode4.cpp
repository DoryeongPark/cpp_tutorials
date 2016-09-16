#include <iostream>
#include <ctime>
#include <cstdlib>	

using namespace std;

/*
*	EvenRandom
*	설명 : 짝수 난수를 생성하는 클래스
*/
class EvenRandom {

public:
	EvenRandom() = default;//기본 생성자 

	int next() noexcept {//짝수 난수 생성

		auto result = 1;//변수 result 홀수로 초기화
		while (result % 2 != 0)//result가 짝수가 아닐 때까지 루프문 실행(짝수일 경우 실행 중단)
			result = rand() % RAND_MAX + 0;//0부터 RAND_MAX까지의 난수 생성하여 result에 대입

		return result;//result 반환
	}

	int nextInrange(const int& a, const int& b)noexcept {//a부터 b사이의 짝수 난수 생성

		auto result = 1;//변수 result 홀수로 초기화
		while (result % 2 != 0) //result가 짝수가 아닐 때까지 루프문 실행(짝수일 경우 실행 중단)
			result = rand() % (b - a + 1) + a;//a부터 b까지의 난수 생성하여 result에 대입

		return result;//result 반환
	}
};

int main() {

	EvenRandom r; //EvenRandom 객체 생성

	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 --" << endl;

	for (int i = 0; i < 10; i++)//반복문 10회 실행
		cout << r.next() << " ";//짝수 난수 생성 및 출력

	cout << endl << endl;

	cout << "-- 2에서 10까지 랜덤 정수 10개 -- " << endl;

	for (int i = 0; i < 10; i++)//반복문 10회 실행
		cout << r.nextInrange(2, 10) << " ";//짝수 난수 생성 및 출력

	cout << endl;
}