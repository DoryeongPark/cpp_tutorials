#include <iostream>
#include <ctime>
#include <cstdlib>	

using namespace std;

/*
*	EvenRandom
*	���� : ¦�� ������ �����ϴ� Ŭ����
*/
class EvenRandom {

public:
	EvenRandom() = default;//�⺻ ������ 

	int next() noexcept {//¦�� ���� ����

		auto result = 1;//���� result Ȧ���� �ʱ�ȭ
		while (result % 2 != 0)//result�� ¦���� �ƴ� ������ ������ ����(¦���� ��� ���� �ߴ�)
			result = rand() % RAND_MAX + 0;//0���� RAND_MAX������ ���� �����Ͽ� result�� ����

		return result;//result ��ȯ
	}

	int nextInrange(const int& a, const int& b)noexcept {//a���� b������ ¦�� ���� ����

		auto result = 1;//���� result Ȧ���� �ʱ�ȭ
		while (result % 2 != 0) //result�� ¦���� �ƴ� ������ ������ ����(¦���� ��� ���� �ߴ�)
			result = rand() % (b - a + 1) + a;//a���� b������ ���� �����Ͽ� result�� ����

		return result;//result ��ȯ
	}
};

int main() {

	EvenRandom r; //EvenRandom ��ü ����

	cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10�� --" << endl;

	for (int i = 0; i < 10; i++)//�ݺ��� 10ȸ ����
		cout << r.next() << " ";//¦�� ���� ���� �� ���

	cout << endl << endl;

	cout << "-- 2���� 10���� ���� ���� 10�� -- " << endl;

	for (int i = 0; i < 10; i++)//�ݺ��� 10ȸ ����
		cout << r.nextInrange(2, 10) << " ";//¦�� ���� ���� �� ���

	cout << endl;
}