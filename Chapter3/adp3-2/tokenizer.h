#pragma once

#include <string>
#include <iostream>
#include <vector>

/*
*  tokenize
*  매개 변수 : str(문자열 원본) / tokens(나눈 문자열을 자정할 정수형 벡터) / delemeters (구분 문자)
*  설명 : 문자열 원본을 구분 문자로 나눈 문자열을 정수로 변환하여 벡터에 저장한다.
*/
void tokenize(const std::string& str, std::vector<int>& tokens, const std::string& delimiters = " ")
{
	int lastPos = str.find_first_not_of(delimiters, 0);
	//구분자가 아닌 첫 번째 문자의 인덱스
	int pos = str.find_first_of(delimiters, lastPos);
	//위치 lastPos로 부터 구분자를 찾고 구분자의 인덱스를 얻는다.

	std::string token;//한 토큰

	while (std::string::npos != pos || std::string::npos != lastPos)
		//값 pos와 npos가 모두 범위를 벗어난 값이 아닐 동안 루프문 실행
	{
		token = str.substr(lastPos, pos - lastPos);
		//lastPos부터 pos - lastPos 위치 까지의 문자열을 때어낸다.
		tokens.push_back(stoi(token));
		//정수형으로 변환하여 벡터에 저장한다.
		lastPos = str.find_first_not_of(delimiters, pos);
		//lastPos에 pos로부터 탐색하여 구분자가 아닌 첫 번째 문자의 위치를 대입한다. 
		pos = str.find_first_of(delimiters, lastPos);
		//pos에 lastPos로부터 탐색하여 구분자가 검색된 위치를 대입한다.
	}
}

