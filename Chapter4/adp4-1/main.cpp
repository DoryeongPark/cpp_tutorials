#include <iostream>

using namespace std;

/*
*	Circle
*	���� : ���� �߻�ȭ�� Ŭ����
*/
class Circle {
	int radius;//������
public:
	Circle() = default;//������
	Circle(const int& _radius) noexcept : radius(_radius) {}//�������� �Ű������� �ϴ� ������
	Circle(Circle& a) noexcept{//���� ������
		radius = a.radius;//������ ����
	}
	int get_radius() noexcept{ return radius; }	//������ Getter
	//������ Setter
	void set_radius(const int& _radius) noexcept { radius = _radius; }
	void swap(Circle& c) noexcept{//������ ���� �Ű����� ���� ������ �����Ѵ�.
		Circle temp = *this;//�ڽ��� �ӽ� ������ ����(���� ����)
		*this = c;//�ڽſ� c�� ���� ����
		c = temp;//temp�� �����ߴ� �ڽ��� ���� c�� ����
	}
};

int main() {

	Circle a{ 1 };//������ 1 Circle ��ü ����
	Circle b{ 2 };//������ 2 Circle ��ü ����

	cout << "Before Swap" << endl;
	cout << "a : " << a.get_radius() << endl;//���� a�� ������ 
	cout << "b : " << b.get_radius() << endl;//���� b�� ������

	a.swap(b);//a�� b ����
	cout << endl;

	cout << "After Swap" << endl;
	cout << "a : " << a.get_radius() << endl;//���� a�� ������
	cout << "b : " << b.get_radius() << endl;//���� b�� ������

}