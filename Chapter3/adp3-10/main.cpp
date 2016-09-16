#include "Histogram.h"

using namespace std;

int main() {
	Histogram elvisHisto{ "Wise men say, only fools rush in But I can't help, " };
	//매개변수 문자열을 가진 Histogram 생성
	elvisHisto.put("falling in love with you");//문자열 추가
	elvisHisto.putc('-');//문자 추가
	elvisHisto.put("Elvis Presley");//문자열 추가

	elvisHisto.print();//히스토그램 내용 출력
}