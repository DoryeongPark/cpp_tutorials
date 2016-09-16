#include <iostream>	
#include <string>

using namespace std;

int main() {

	//함수 bigger : 두 수를 비교하여 큰 수를 3번째 매개변수에 저장
	auto bigger = [&](int a, int b, int& big)->bool {
		if (a > b) {//a가 더 큰 경우
			big = a;//big에 a 저장
			return false;
		}
		else if (a < b) {//b가 더 큰 경우
			big = b;//big에 b 저장
			return false;
		}
		else {
			return true;//두 수가 같을 경우 true 반환
		}
	};
	
	string input1{};//정수1
	string input2{};//정수2
	
	cout << "Input \"exit\" to finish." << endl;

	while(true) {
		auto big = 0;//큰 수를 담을 변수

		cout << "정수 1 >> ";
		getline(cin, input1, '\n');//정수1 입력
		cout << "정수 2 >> ";
		getline(cin, input2, '\n');//정수2 입력
		//하나라도 exit 입력 시 종료
		if (input1 == "exit" || input2 == "exit")
			exit(0);

		//입력 예외처리
		try {
			if (!bigger(stoi(input1), stoi(input2), big))//두 수가 다를 경우
				cout << "큰 수: " << big << endl;//큰 수 출력
			else//두 수가 같을 경우
				cout << "두 수가 같습니다." << endl;
		}
		catch (exception e) {//입력 예외가 발생할 경우
			cout << e.what() << endl;//오류 출력
		}
	}
}