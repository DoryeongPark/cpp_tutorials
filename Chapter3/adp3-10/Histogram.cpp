#include "Histogram.h"

//히스토그램 클래스 정의
using namespace std;
//문자열을 매개변수로 하는 생성자
Histogram::Histogram(const string& input)noexcept {
	initialize_analyzer();//map 초기화
	s = input;//문자열 대입
	update_analyzer();//문자열을 분석하여 map 갱신
}
//문자를 매개변수로 하는 생성자
Histogram::Histogram(const char& input) noexcept {
	initialize_analyzer();//map 초기화
	s.append(1, input);//문자 대입
	update_analyzer();//문자열을 분석하여 map 갱신
}
//문자열 추가
void Histogram::put(const string& input) noexcept {
	s.append(input);//멤버변수에 문자열을 추가한다.
	update_analyzer();//갱신된 문자열을 분석한다.
}
//문자 추가
void Histogram::putc(const char& input) noexcept {
	s.append(1, input);//멤버변수에 문자를 추가한다.
	update_analyzer();//갱신된 문자열을 분석한다.
}
//map의 key(a ~ z)의 value들을 0으로 초기화한다.
void Histogram::initialize_analyzer() noexcept {
	for (char c = 97; c <= 122; c++)//a ~ z
		analyzer[c] = 0;//0으로 초기화
}
//갱신된 문자열을 map이 분석한다.
void Histogram::update_analyzer() noexcept {

	analyzer.clear();//기존의 map을 지운다.
	
	initialize_analyzer();//map 초기화 setting

	for (auto c : s) {//새로운 문자열
		if((c >= 97 && c <= 122) || (c >= 65 && c <= 90))//소문자나 대문자일 경우
			analyzer[tolower(c)] += 1;//해당 value를 1 증가시킨다.
	}
}
//현재 map의 정보를 히스토그램으로 표현한다.
void Histogram::print() noexcept {

	cout << s << endl;//현재 문자열 출력
	
	int accum = 0;//현재 알파벳의 개수

	for (char c = 97; c <= 122; ++c)
		accum += analyzer[c];//개수를 누적시킨다.

	cout << "총 알파벳 수 : " << accum << endl;//알파벳의 개수 출력
	
	for (auto kv : analyzer) {//analyzer 반복문
		string star;//별 문자열
		star.append(kv.second, '*');//해당 알파벳(Key)의 개수(Value)만큼 별을 추가한다.
		cout << kv.first << " (" << kv.second << ") : " << star << endl;//해당 알파벳(Key)와 별의 개수(Value) 출력
	}
}