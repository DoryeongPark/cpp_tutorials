#pragma once
#include "Box.h"

using namespace std;

int main() {
	Box b{ 10 , 2 };//���� 10, ���� 2�� �ڽ� ��ü ����
	b.draw();//�ڽ������� �׸���
	cout << endl;
	b.setSize(7, 4);//���� 7, ���� 4�� ����
	b.setFill('^');//ä���� ^�� ����
	b.draw();//�ڽ������� �׸���
}