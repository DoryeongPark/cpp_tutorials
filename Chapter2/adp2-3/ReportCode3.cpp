#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
/*
*	Random 클래스 정의
*/
class Random {
public:
	Random() = default;//디폴트 생성자 
	int next();//0 ~ RAND_MAX 사이의 난수 생성
	int nextInRange(const int& _a, const int& _b);//a ~ b 사이의 난수 생성
};

//Random 클래스 정의부 
int Random::next() {
	return rand() % RAND_MAX + 0;//0부터 RAND_MAX까지의 난수 생성 뒤 반환
}

int Random::nextInRange(const int& a, const int& b) {
	return rand() % (b - a + 1) + a;//a부터 b까지의 난수 생성 뒤 반환
}

int main() {

	srand((unsigned int)time(NULL));//시드 값 생성

	Random r;//Random 객체 생성

	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개 --" << endl;

	for (int i = 0; i < 10; i++) {//반복문 10번 실행
		int n = r.next();//난수 하나 생성
		cout << n << ' ';//출력
	}

	cout << endl << endl << "-- 2에서 4까지 랜덤 정수 10개 --" << endl;

	for (int i = 0; i < 10; i++) {//반복문 10번 실행
		int n = r.nextInRange(2, 4);//2에서 4사이의 난수 하나 생성
		cout << n << " ";//출력
	}
	cout << endl;
}

