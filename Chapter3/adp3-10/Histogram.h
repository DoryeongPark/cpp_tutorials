#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

//히스토그램 클래스 정의
class Histogram {
	std::string s;//분석할 문자열
	std::map<char, int> analyzer;//문자열 분석 map<char, int>
public:
	Histogram() = default;//디폴트 생성자
	Histogram(const std::string& input) noexcept;//매개변수가 문자열인 생성자
	Histogram(const char& input) noexcept;//매개변수가 문자인 생성자
	void put(const std::string& input) noexcept;//문자열 추가
	void putc(const char& input)noexcept;//문자 추가
	void initialize_analyzer() noexcept;//모든 인덱스를 0으로 초기화
	void update_analyzer()noexcept;//갱신된 문자열을 대상으로 분석
	void print()noexcept;//문자열 히스토그램 출력
};

