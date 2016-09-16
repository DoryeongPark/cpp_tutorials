#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* tokenize
*  매개 변수 : str(문자열 원본) / tokens(나눈 문자열을 자정할 문자열 벡터) / delemeters (구분 문자)
*  설명 : 문자열 원본을 구분 문자로 나눈 문자열을 스트링 벡터에 저장한다.
*/
void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	int lastPos = str.find_first_not_of(delimiters, 0);
	//구분자가 아닌 첫 번째 문자의 인덱스
	int pos = str.find_first_of(delimiters, lastPos);
	//위치 lastPos로 부터 구분자를 찾고 구분자의 인덱스를 얻는다.

	while (string::npos != pos || string::npos != lastPos)
		//값 pos와 npos가 모두 범위를 벗어난 값이 아닐 동안 루프문 실행
	{
		tokens.push_back(str.substr(lastPos, pos - lastPos));
		//lastPos부터 pos - lastPos 위치 까지의 문자열을 때어내어 벡터에 저장한다.
		lastPos = str.find_first_not_of(delimiters, pos);
		//lastPos에 pos로부터 탐색하여 구분자가 아닌 첫 번째 문자의 위치를 대입한다. 
		pos = str.find_first_of(delimiters, lastPos);
		//pos에 lastPos로부터 탐색하여 구분자가 검색된 위치를 대입한다.
	}
}
/*
*	Date
*	멤버변수 : year - 년도 / month - 월 / day - 일
*	설명 : 날짜를 추상화한 클래스
*/
class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() = default;//디폴트 생성자
					 //매개변수로 3개의 정수를 받는 생성자
	Date(const int& y, const int& m,
		const int& d) noexcept {
		year = y; month = m; day = d;
		//매개변수 년, 월, 일 대입
	}
	//매개변수를 문자로 받는 생성자
	Date(const string& input) noexcept {

		vector<string> tokens{};
		//구분자로 나누인 문자열들을 저장할 벡터
		tokenize(input, tokens, "/");
		//input의 문자열을 '/'를 구분 문자로 문자열을 나누어 벡터에 저장한다.
		year = stoi(tokens.at(0));//나뉜 첫 번째 문자열 대입
		month = stoi(tokens.at(1));//나뉜 두 번째 문자열 대입
		day = stoi(tokens.at(2));//나뉜 세 번째 문자열 대입
	}
	~Date() = default;//디폴트 소멸자
	int getYear() { return year; }//현재 년도 반환
	int getMonth() { return month; }//현재 월 반환
	int getDay() { return day; }//현재 일 반환
								//현재 년, 월, 일에 대한 정보를 출력한다.
	void show() { cout << year << "년" << month << "월" << day << "일" << endl; }
};
int main() {
	Date birth{ 2014, 3, 20 };//년, 월, 일이 2014, 3, 20인 날짜 생성
	Date independenceDay{ "1945/8/15" };//년, 월, 일이 1945, 8, 15 날짜 생성

	independenceDay.show();//indpendeceDay 객체 정보 출력
	cout << birth.getYear() << "," << birth.getMonth() << "," <<
		birth.getDay() << endl;
	//birth 객체의 정보 각자 출력
}