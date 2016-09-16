#include <iostream>	
#include <string>
#include <vector>
#include <algorithm>

const double M_PI = 3.141592; //������ ��� ����

using namespace std;

/*
*	Circle
*	���� : ���� �߻�ȭ�� Ŭ����
*	�߰� : ��� �Է� ����ó��
*/
class Circle {
private:
	double radius; //������
	double area; //�� ����
	int num; //�� ��ȣ

protected:
	static int circle_number;//Ŭ���� ���� �� ��ȣ(�Ҵ��)

public:
	//��ü ������ ���ÿ� �� ���� �Է�
	Circle() noexcept{

		num = ++circle_number;//�� ��ȣ �Ҵ� �� ����

		cout << "�� " << num << "�� ������ >> ";
		//������ �Է¹޴´�. ���� ���� �̿��� ���� ���ۿ� ���� ���
		while (!(cin >> radius))
		{	
			cin.clear();//���۸� ����ְ�

			while (cin.get() != '\n')//���๮�ڸ� �����ش�.
				continue;
			
			cout << "���ڸ� �Է��ϼ���." << endl;//�˸� ����
			cout << "�� " << num << "�� ������ >> ";
		}

		area = M_PI * radius * radius;//���� ���̸� ����Ͽ� ������� ����
	}
	~Circle() noexcept{
		circle_number--;//��ü �Ҹ�� �Ҵ�� ���� ����
	}
	//�� ���� ��ȯ
	double getArea() noexcept {
		return area;
	}
	//�� ��ȣ ��ȯ
	int getCircleNum() noexcept {
		return num;
	}
};

int Circle::circle_number = 0;//Ŭ���� ���� �ʱ�ȭ

int main() {

	int arr_size;//�Է��� �迭 ������

	cout << "���� ���� >> ";
	//������ �Է¹޴´�. ���� ���� �̿��� ���� ���ۿ� ���� ���
	while (!(cin >> arr_size)) {
		cin.clear();//���۸� ����.

		while (cin.get() != '\n')//���๮�ڸ� �����ش�.
			continue;

		cout << "���ڸ� �Է��ϼ���." << endl;//�˸� ����
		cout << "���� ���� >>" << endl;
	}

	Circle* c_arr = new Circle[arr_size];//Circle��ü �迭 ����
	vector<Circle> v;//Circle�� ���� ����
	//������ 100���� ū ���� ���Ϳ� �ִ´�.
	for (int i = 0; i < arr_size; i++) {
		if (i[c_arr].getArea() > 100)
			v.push_back(i[c_arr]);
	}
	//������ 100���� ū ���� ���� ���
	cout << "������ 100���� ū ���� " << v.size() << "�� �Դϴ�." << endl;
	//������ 100���� ū ������ ���� ���
	for_each(v.cbegin(), v.cend(), [&](Circle c) {
		cout << "�� " << c.getCircleNum() << " : " << c.getArea() << endl;
	});

	delete[] c_arr;	//�޸𸮸� ���� �Ҵ��� �迭 �Ҹ�
}