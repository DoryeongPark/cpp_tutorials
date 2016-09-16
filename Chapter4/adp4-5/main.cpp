#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
*	MyintStack
*	설명 : 정수형 스택을 추상화 하였다.
*/
class MyIntStack {
	vector<int> v;//정수형 배열
public:
	MyIntStack() noexcept { v.reserve(10); }//10만큼 공간 미리 할당
	//정수 n을 push한다.
	bool push(const int& n) noexcept {
		if (v.size() >= 10) {//배열의 원소가 10개인 경우
			return false;//더 이상 넣을 수 없으므로 false 반환
		}
		else {//배열의 원소가 10개 미만인 경우
			v.push_back(n);//정수 n push
			return true;
		}		
	}
	//정수 n을 pop하고 매개변수를 통해 참조한다.
	bool pop(int& n) noexcept {
		if (v.size() <= 0) {//현재 사이즈가 0일 경우
			return false;//더 이상 원소를 뺄 수 없음
		}
		else {
			n = v.back();//가장 뒤에 있는 원소를 매개변수로 참조
			v.pop_back();//뒤에 있는 원소 pop
			return true;//pop 수행 
		}
	}

};
int main() {
	MyIntStack a{};//정수형 스택 객체 생성
	
	for (int i = 0; i < 11; ++i) {
		if (a.push(i))//정상적으로 push된 경우
			cout << i << ' ';//push 된 정수 출력
		else//아닌 경우
			cout << endl << i + 1 << "번째 stack full" << endl;
			//스택이 가득 찼음을 알림
	}
	
	auto n = 0;//pop된 정수를 받어올 변수

	for (int j = 0; j < 11; ++j) {
		if (a.pop(n))//정상적으로 pop된 경우
			cout << n << ' ';//pop된 정수 출력
		else
			cout << endl << j + 1 << "번째 stack empty" << endl;
			//스택이 비어있음을 알림
	}
	
	cout << endl;
}