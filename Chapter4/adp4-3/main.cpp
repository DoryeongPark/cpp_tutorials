#include <iostream>	

using namespace std;

class Circle {
	int radius;
public:
	Circle() :radius(0) {}//�⺻ ������ radius = 0
	//�Ű������� �������� set�ϴ� ������
	Circle(const int& r) noexcept { radius = r; }
	//���� ������(������ ����)
	Circle(const Circle& b) { radius = b.radius; }
	//������ Getter
	int getRadius() noexcept { return radius; }
	//������ Setter
	void setRadius(const int& r) { radius = r; }
	//������ ���
	void show() noexcept {
		cout << "�������� " << radius << " �� ��" << endl;
	}
	//������ �����ε� ���� : �� ���� �������� ���Ѵ�.
	Circle operator+(Circle& b) noexcept {
		return Circle(radius + b.getRadius());//�� �������� ������ ��ü ��ȯ
	}
};

void main() {

	auto increaseBy = [&](Circle& a, Circle& b) {
		a = a + b;//��ü a�� b�� ���Ѵ�.
	};

	Circle x{ 10 }, y{ 5 };//������ 10, 5�� �� ���� ����
	increaseBy(x, y);//�� ��ü x�� y�� ���Ѵ�.
	x.show();//x�� ������ ���
}