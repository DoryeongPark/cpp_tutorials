#include "Circle.h"
#include <vector>
#include <algorithm>	

using namespace std;
//�߰� : ��� �Է� ����ó��
int main() {

	vector<Circle*> v;//Circle ��ü ������ �迭
	vector<Circle*> bigger_than_100;//������ 100���� ū ���� ��ũ
	//�� 3���� �����Ͽ� �迭�� �ִ´�.
	for (int i = 0; i < 3; ++i) {
		v.push_back(new Circle());
	}
	//���� 100�� �Ѵ� �� �˻�
	for (auto c : v) {
		if (c->getArea() > 100) //�ش� ���� ������ 100�� ���� ���
			bigger_than_100.push_back(c);//100���� ū ������ ���� �迭�� �ִ´�.
		
	}
	//������ 100���� ū ���� ���� ���
	cout << "������ 100���� ū ���� " << bigger_than_100.size() << "�� �Դϴ�." << endl;
	//������ 100���� ū ���� ���� ���ʷ� ���
	for_each(bigger_than_100.cbegin(), bigger_than_100.cend(), [&](Circle* c) {
		cout << "��" << c->getCircleNum() << " : " << c->getArea() << endl;
	});


	for (auto c : v)//�迭�� �����ϴ� ��� �� ��ü �޸� ����
		delete c;
}