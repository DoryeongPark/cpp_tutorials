#include "Circle.h"

using namespace std;
//Circle Ŭ���� ��� ����
int Circle::circle_num = 1;//Ŭ���� ���� �ʱ�ȭ

Circle::Circle() {

	num = circle_num++;//���� ������� �� ��ȣ �Ҵ� �� ����

	cout << "�� " << num << "�� ������ >> ";

	string input;//�Է¹��� ���ڿ�

	try {//���� �˻�
		getline(cin, input, '\n');//���ڿ��� �Է¹޴´�.

		for (auto c : input) {//���� �ϳ��� �˻�
			if (!(isdigit(c) || c == '.'))//���ڰ� ���� �Ǵ� .�� �ƴ� ���
				throw input;//���ܸ� ó���Ѵ�.
		}
	}
	catch (...) {//���� ó�� ����
		cout << " ���ڰ� �ƴմϴ�." << endl;
		exit(0);//���� �Է� �� ����
	}

	radius = stod(input);//�Է¹��� ���ڿ��� double������ ��ȯ
	area = M_PI * radius * radius;//�� ���̸� ����Ͽ� ��������� ����
}

Circle::~Circle() noexcept {
	circle_num--;//�Ҹ��� �� Ŭ���� ���� ����
}
//�� ���� ��ȯ
double Circle::getArea() noexcept {
	return area;
}
//�� ��ȣ ��ȯ
int Circle::getCircleNum() noexcept {
	return num;
}

