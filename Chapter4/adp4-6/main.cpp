#include <iostream>	
#include <memory>
#include <algorithm>

using namespace std;

class MyIntStack {
	unique_ptr<int> p;//배열 포인터 
	int size;//배열 사이즈
	int top = -1;//현재 가장 뒤에 있는 원소의 인덱스

public:
	MyIntStack() = default;//기본 생성자(default)
	
	//사이즈만큼 배열을 동적 생성한다.
	explicit MyIntStack(const int& size) noexcept:size(size){
		p.reset(new int[size]);
	}
	//복사 생성자
	MyIntStack(MyIntStack& s) {
		p.reset(new int[s.size]);//복사할 객체의 배열 사이즈만큼 배열 생성
		top = s.top; size = s.size;//복사할 객체의 top, size 복사
		for (int i = 0; i < s.size; ++i)//배열의 원소 복사
			i[p.get()] = s.at(i);
	}
	//스마트 포인터가 알아서 메모리 해제(소멸자 필요없음)
	~MyIntStack() = default;

	int at(const int& n) noexcept{//현재 배열의 원소 반환
		return n[p.get()];
	}
	//정수 n을 배열에 push한다.
	bool push(const int& n) noexcept {
		if (top >= 9) {//top이 가리키고 있는 인덱스가 9이면 10개가 모두 차있는 상태
			return false;//push 불가
		}
		else {
			(++top)[p.get()] = n;//원소 push 및 top증가
			return true;
		}
	}
	//원소를 pop하고 pop한 원소를 매개변수로 참조
	bool pop(int& n) noexcept {
		if (top <= -1) {//가리키고 있는 인덱스가 -1라는 것은 원소가 없는 상태
			return false;//pop 불가
		}
		else {
			n = top[p.get()];//가리키고 잇는 원소를 매개변수로 참조
			//원소가 빠진 곳을 NULL 포인터로 만들고 감소
			(top--)[p.get()] = static_cast<int>(NULL);
			return true;
		}
	}
};
int main() {
	MyIntStack a{ 10 };//10사이즈의 스택 생성
	a.push(10);//10 push
	a.push(20);//20 push

	MyIntStack b = a;//10, 20 push된 상태 스택 b에 복사
	b.push(30);//b에 30 push

	int n;
	a.pop(n);//a에서 pop
	cout << "스택 a에서 팝한 값 : " << n << endl;//pop한 값 확인
	b.pop(n);//b에서 pop
	cout << "스택 b에서 팝한 값 : " << n << endl;//pop한 값 확인
}