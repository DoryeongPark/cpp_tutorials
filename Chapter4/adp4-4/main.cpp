#include <iostream>
#include <string>

using namespace std;

int main() {
	//함수 find(문자열, 찾을 문자, 찾은 여부 Flag)
	auto find = [&](string& a, const char& c, bool& success) ->char&{
		if (a.find_first_of(c) != string::npos) {//문자열에서 해당 문자를 찾았을 경우
			success = true;//Flag를 true로 바꾼다.
			return a.at(a.find_first_of(c));//해당 인덱스의 문자 참조를 return
		}
	};

	string s = "Mike";//원래 문자열
	bool b = false;//플래그값 초기 설정
	char &loc = find(s, 'M', b);//해당 문자가 존재할 경우 참조 반환 및 b = true

	if (b == false) {//플래그가 true 바뀌지 않았을 경우
		cout << "M을 발견할 수 없다." << endl;//문구 출력
		exit(0);//종료
	}

	loc = 'm';//참조를 이용하여 string s내의 값을 바꾼다.
	cout << s << endl;//바뀐 값을 확인하기 위해 원본 문자열 출력 
}