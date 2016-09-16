#include <iostream>	
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>	

using namespace std;

/*
*	SelectableRandom
*	멤버변수 : v - 10개의 짝수 또는 홀수를 가지고 있는 벡터
*	설명 : 짝수 또는 홀수의 난수 10개를 가지고 있는 클래스
*/
class SelectableRandom {
private:
	vector<int> v;
public:
	SelectableRandom() = default;//디폴트 생성자

								 //생성자
								 //매개변수 : isOdd - 짝수(0), 홀수(1) / first부터 last까지의 난수 생성
	SelectableRandom(const bool& isOdd,
		const int& first, const int& last) noexcept {

		v.reserve(10);//벡터에 공간 10을 미리 할당

					  //홀수
		while (isOdd && v.size() != 10) {//홀수 옵션이고 Vector가 10개의 원소를 가질 때까지 반복문 실행
			auto&& number = rand() % (last - first + 1) + first;
			//first부터 last까지의 난수 생성
			if (!(number % 2))//생성한 난수가 홀수일 경우
				v.push_back(number);//벡터에 넣는다
		}
		//짝수
		while (!isOdd && v.size() != 10) {//짝수 옵션이고 Vector가 10개 원소를 가질 때까지 반복문 실행
			auto&& number = rand() % (last - first + 1) + first;
			//first부터 last까지의 난수 생성
			if (number % 2)//생성된 난수가 짝수일 경우
				v.push_back(number);//벡터에 넣는다
		}
	}

	void show() {//벡터의 내용을 출력한다.
		for_each(v.cbegin(), v.cend(), [&](int a) {
			cout << a << " ";
		});
		//벡터의 처음부터 마지막까지 출력한다.
	}
};
int main() {

	srand((unsigned int)time(NULL));//시드값 생성

	SelectableRandom a{ 1, 0, RAND_MAX };//홀수의 0부터 RAND_MAX사이의 난수 10개 생성
	SelectableRandom b{ 0, 2, 10 };//짝수의 2부터 10사이의 난수 10개 생성

	cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10개" << "--" << endl;

	a.show();//객체 a의 내용 출력

	cout << endl << endl;

	cout << "-- 2에서 10까지 홀수 랜덤 정수 10개 --" << endl;

	b.show();//객체 b의 내용 출력
}