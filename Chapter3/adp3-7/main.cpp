#include <iostream>	
#include <string>

using namespace std;

/*
*	Person
*	설명 : 사람의 정보를 추상화한 클래스
*/
class Person {
	string name;//이름
	string tel;//전화번호
	int num;//번호
protected:
	static int person_num;//번호 할당용 클래스 변수
public:
	//생성되자마자 정보를 입력받는다.
	Person() noexcept{

		num = ++person_num;//번호를 할당 받고 증가

		string input;//입력할 문자열

		cout << "사람 " << num << ">> ";

		getline(cin, input, '\n');//문자열을 입력받는다

		name = input.substr(0, input.find(' ', 0));//공백을 구분자로 첫 번째 string 추출(name)
		tel = input.substr(input.find(' ', 0) + 1, 
			(input.find(' ', input.find(' ', 0) + 1)) - 
			(input.find(' ', 0) + 1));//공백을 구분자로 두 번째 string 추출(tel)
	}
	//이름 반환
	string getName() noexcept {
		return name;
	}
	//전화번호 반환
	string getTel() noexcept {
		return tel;
	}
};

int Person::person_num = 0;
using namespace std;

int main() {

	cout << "이름과 전화 번호를 입력해 주세요." << endl;
	
	Person* p_arr = new Person[3];//Person 객체 배열 생성

	cout << "모든 사람의 이름은 " << endl;
	//배열 내의 각 Person의 이름 출력
	for (int i = 0; i < 3; ++i) 
		cout << i[p_arr].getName() << endl;
	

	string name_input;//검색할 이름

	cout << "전화번호를 검색합니다. 이름을 입력하세요 >> ";

	getline(cin, name_input, '\n');//검색할 이름 입력

	//반복문을 이용하여 검색한 이름을 차례로 비교한다.
	for (int i = 0; i < 3; ++i) {
		if (name_input == i[p_arr].getName())//검색한 이름과 사람의 이름이 같을 경우
			cout << "전화번호는 " << p_arr[i].getTel() << endl;//해당 사람의 전화번호 출력
	}

	delete[] p_arr;//Circle객체 배열 메모리 해제 
}
