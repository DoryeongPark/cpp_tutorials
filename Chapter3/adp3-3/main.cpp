#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>	

using namespace std;
/*
*	RandomString
*	설명 : 입력받은 문자열의 한 글자가 랜덤하게 바뀌는 문자열이다.
*	추가 : 공백문자는 문자로 바뀌지 않게 처리하였음. 항상 기존 문자와는 다른 문자로 바뀌도록 처리하였음.
*/
class RandomString {
	string replaced_string;//바뀐 문자열

public:
	//생성자
	//객체가 생성되자마자 입력받는다.
	RandomString() noexcept {

		string input;//입력한 문자
		vector<int>	space_index;//입력한 문자열의 공백문자들의 인덱스를 저장하는 벡터

		cout << ">>";

		getline(cin, input, '\n');//문자열을 입력받는다.

		if (input == "exit")//입력한 문자열이 exit일 경우
			exit(0);//프로그램 종료

		int sp = 0;//공백문자를 찾을 start point

		while (input.find(' ', sp) != string::npos) {
			space_index.push_back(input.find(' ', sp));//공백문자의 인덱스를 벡터에 저장
			sp = input.find(' ', sp);//start point 갱신
			sp++;
		}

		auto random_index = -1;//랜덤 문자를 삽입할 인덱스
		
		while (random_index == -1) {
			random_index = rand() % input.size(); //랜덤 위치 인덱스 생성
			//만약 생성한 랜덤 위치 인덱스가 공백 문자의 인덱스이면 find_if문을 종료하고 다시 생성
			find_if(space_index.begin(), space_index.end(), [&](auto index)->bool {
				if (random_index == index) {
					random_index = -1;//무한루프 조건
					return true;
				}
				return false;
			});
		}

		char ch = ' ';//랜덤 생성 문자
		
		for(;;) {
			ch = rand() % 26 + 97;//랜덤 문자 생성
			//생성한 랜덤문자가 랜덤 인덱스의 문자와 다를 경우
			if (input.at(random_index) != ch)
				break;//무한루프 탈출
		}

		string random_ch{ ch };//랜덤문자를 문자열로 Wrapping
		//바뀐 문자 위치 출력
		cout << random_index + 1 << "번째 문자가 바뀌었습니다." << endl;
		//문자열의 랜덤 인덱스의 문자에 랜덤 문자로 치환한다.
		replaced_string = input.replace(random_index, 1 ,random_ch);
		//바뀐 문자 출력
		cout << ">>" <<  replaced_string << endl;

		string arrow{};//화살표
		//바뀐 인덱스만큼 공백문자 나열
		for (int i = 0; i < random_index + 2; ++i) 
			arrow.append(" ");
		
		arrow.append("^");//바뀐 위치 화살표로 출력
		
		cout << arrow << endl;//화살표 출력
	}

};

int main() 
{
	srand((unsigned int)time(NULL));//시드값

	cout << "아래에 한줄을 입력하세요.(exit를 입력하면 종료합니다)." << endl;

	for (;;) {
		RandomString s{};//문자열 입력받고 바뀐 문자열 출력
	}
}
	
