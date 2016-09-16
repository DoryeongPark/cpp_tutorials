#include "Box.h"	

using namespace std;

//Box Ŭ���� �Լ� ���Ǻ� 

Box::Box(int w, int h) {
	setSize(w, h);//w�� h�� �Ű������� �޾Ƽ� ����
	fill = 'x';//�ڽ��� x�� ä���.
}

void Box::setFill(char f) {
	fill = f;//ä���ڸ� set�Ѵ�.
}

void Box::setSize(int w, int h) {//���ο� ���̸� set�Ѵ�.
	width = w;
	height = h;
}

void Box::draw() {//���ο� ���̸�ŭ ä���ڷ� ä���.
	for (int n = 0; n < height; n++) {//������ ���̸�ŭ �ݺ��� ����
		for (int m = 0; m< width; m++) {//������ ���θ�ŭ �ݺ��� ����
			cout << fill;//ä���� ���
		}
		cout << endl;
	}
}