#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
/*
*	Random Ŭ���� ����
*/
class Random {
public:
	Random() = default;//����Ʈ ������ 
	int next();//0 ~ RAND_MAX ������ ���� ����
	int nextInRange(const int& _a, const int& _b);//a ~ b ������ ���� ����
};

//Random Ŭ���� ���Ǻ� 
int Random::next() {
	return rand() % RAND_MAX + 0;//0���� RAND_MAX������ ���� ���� �� ��ȯ
}

int Random::nextInRange(const int& a, const int& b) {
	return rand() % (b - a + 1) + a;//a���� b������ ���� ���� �� ��ȯ
}

int main() {

	srand((unsigned int)time(NULL));//�õ� �� ����

	Random r;//Random ��ü ����

	cout << "--0���� " << RAND_MAX << "������ ���� ���� 10�� --" << endl;

	for (int i = 0; i < 10; i++) {//�ݺ��� 10�� ����
		int n = r.next();//���� �ϳ� ����
		cout << n << ' ';//���
	}

	cout << endl << endl << "-- 2���� 4���� ���� ���� 10�� --" << endl;

	for (int i = 0; i < 10; i++) {//�ݺ��� 10�� ����
		int n = r.nextInRange(2, 4);//2���� 4������ ���� �ϳ� ����
		cout << n << " ";//���
	}
	cout << endl;
}

