#include "Circle.h"
#include <vector>
#include <algorithm>	

using namespace std;
//추가 : 모든 입력 예외처리
int main() {

	vector<Circle*> v;//Circle 객체 포인터 배열
	vector<Circle*> bigger_than_100;//면적이 100보다 큰 원들 링크
	//원 3개를 생성하여 배열에 넣는다.
	for (int i = 0; i < 3; ++i) {
		v.push_back(new Circle());
	}
	//면적 100이 넘는 원 검사
	for (auto c : v) {
		if (c->getArea() > 100) //해당 원의 면적이 100을 넘을 경우
			bigger_than_100.push_back(c);//100보다 큰 원들을 위한 배열에 넣는다.
		
	}
	//면적이 100보다 큰 원의 개수 출력
	cout << "면적이 100보다 큰 원은 " << bigger_than_100.size() << "개 입니다." << endl;
	//면적이 100보다 큰 원의 정보 차례로 출력
	for_each(bigger_than_100.cbegin(), bigger_than_100.cend(), [&](Circle* c) {
		cout << "원" << c->getCircleNum() << " : " << c->getArea() << endl;
	});


	for (auto c : v)//배열에 존재하는 모든 원 객체 메모리 해제
		delete c;
}