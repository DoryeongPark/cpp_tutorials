#include "Histogram.h"

using namespace std;

int main() {
	Histogram elvisHisto{ "Wise men say, only fools rush in But I can't help, " };
	//�Ű����� ���ڿ��� ���� Histogram ����
	elvisHisto.put("falling in love with you");//���ڿ� �߰�
	elvisHisto.putc('-');//���� �߰�
	elvisHisto.put("Elvis Presley");//���ڿ� �߰�

	elvisHisto.print();//������׷� ���� ���
}