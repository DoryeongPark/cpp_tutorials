#include "tokenizer.h"
#include <algorithm>
//추가 : 모든 입력 예외 처리
using namespace std;

class Sample {
	vector<int>* v;//정수형 배열 포인터
	int size;//배열이 가지고 있는 원소 수
public:
	//생성자
	Sample(const int& n)noexcept : size(n), v(new vector<int>) { v->reserve(n); }
	//동적 할당 받은 정수 배열(벡터)에 p에 사용자로부터 정수를 입력, 입력받은 사이즈 만큼 공간 미리 할당
	void read(){
		string input;
		getline(cin, input, '\n');//문자열을 입력받는다.

		try {//예외 검사
			tokenize(input, *v);//문자열을 공백을 구분자로 나누어 정수형 배열에 저장
		}
		catch (...) {//입력한 것 중 정수가 아닌 것이 있을 경우 구문 실행
			cout << "정수를 입력하세요." << endl;//예외 처리
		}
	}
	//정수 배열을 화면에 출력
	void write() noexcept{
		//반복문을 사용하여 정수형 배열의 내용 출력
		for_each(v->cbegin(), v->cend(), [&](int i){
			cout << i << ' ' ;
		});
		cout << endl;
	}
	//정수 배열에서 가장 큰 수 리턴
	int big() noexcept {
		auto max = 0;//가장 큰 수를 담을 변수 선언
		for (auto i : *v) {
			if (i > max)//만약 배열에서 꺼낸 정수가 현재 가장 큰 수보다 클 경우
				max = i;//그 수를 가장 큰 수로 대입한다.
		}
		return max;//가장 큰 수 반환
	};
	//소멸자
	~Sample() { delete v; }//Sample 객체가 소멸할 때 따라서 소멸
	//벡터이므로 포인터가 가리키는 것만 소멸 ([] 추가 안해도 됨)
};

int main() {
	Sample s{ 10 };//사이즈 10을 미리 할당받은 Sample 객체 생성
	s.read();//입력받은 정수들을 읽는다.
	s.write();//읽어들인 정수들을 출력한다.
	cout << "가장 큰 수는 " << s.big() << endl;//가장 큰 수 출력
}