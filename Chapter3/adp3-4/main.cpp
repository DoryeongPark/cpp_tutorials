#include <iostream>
#include <string>

using namespace std;

/*
*	ReverseString
*	설명 : 입력한 문자열이 거꾸로 출력되는 문자열
*/
class ReverseString {
	string reverse_string;//거꾸로 출력되는 문자열

public:
	//생성되자마자 문자열을 입력받는다.
	ReverseString() noexcept{
		cout << ">>";
		//문자열을 입력받는다.
		getline(cin, reverse_string, '\n');
		//만약 입력받은 문자열이 exit일 경우
		if (reverse_string == "exit")
			exit(0);//프로그램 종료
		//입력받은 문자열의 순서를 거꾸로 바꾼다.
		reverse(reverse_string.begin(), reverse_string.end());
	}
	
	//바꾼 문자열 반환
	string get_string() noexcept {
		return reverse_string;
	}
};
int main() {
	cout << "아래에 한줄을 입력하세요. (exit를 입력하면 종료합니다.)" << endl;

	for (;;) {
		ReverseString r{};//문자열을 입력받고 문자열의 순서를 바꾼다.
		cout << r.get_string() << endl;//순서가 바뀐 문자열 출력
	}
}