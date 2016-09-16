#include <iostream>	

using namespace std;

/*
*	Accumulator
*	���� : ���� ������ �� �ִ� Ŭ����
*/
class Accumulator {
	int value;//���� value

public:
	Accumulator() = default;//�⺻ ������(default)

	//�Ű������� value�� set�ϴ� ������
	explicit Accumulator(const int& value) noexcept{
		this->value = value;
	}
	
	//���� value�� �Ű����� �߰�
	Accumulator& add(const int& n) noexcept{
		value += n;
		return *this;//�ڽ� ��ȯ
	}

	int get() noexcept { return value; }//value getter	
};
int main() {
	Accumulator acc{ 10 };//value 10�� ������ �ִ� ��ü ����

	cout << acc.add(5).add(6).add(7).get() << endl;//10 + 5 + 6 + 7 = 28
}