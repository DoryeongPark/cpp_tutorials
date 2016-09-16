#include <iostream>	
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>	

using namespace std;

/*
*	SelectableRandom
*	������� : v - 10���� ¦�� �Ǵ� Ȧ���� ������ �ִ� ����
*	���� : ¦�� �Ǵ� Ȧ���� ���� 10���� ������ �ִ� Ŭ����
*/
class SelectableRandom {
private:
	vector<int> v;
public:
	SelectableRandom() = default;//����Ʈ ������

								 //������
								 //�Ű����� : isOdd - ¦��(0), Ȧ��(1) / first���� last������ ���� ����
	SelectableRandom(const bool& isOdd,
		const int& first, const int& last) noexcept {

		v.reserve(10);//���Ϳ� ���� 10�� �̸� �Ҵ�

					  //Ȧ��
		while (isOdd && v.size() != 10) {//Ȧ�� �ɼ��̰� Vector�� 10���� ���Ҹ� ���� ������ �ݺ��� ����
			auto&& number = rand() % (last - first + 1) + first;
			//first���� last������ ���� ����
			if (!(number % 2))//������ ������ Ȧ���� ���
				v.push_back(number);//���Ϳ� �ִ´�
		}
		//¦��
		while (!isOdd && v.size() != 10) {//¦�� �ɼ��̰� Vector�� 10�� ���Ҹ� ���� ������ �ݺ��� ����
			auto&& number = rand() % (last - first + 1) + first;
			//first���� last������ ���� ����
			if (number % 2)//������ ������ ¦���� ���
				v.push_back(number);//���Ϳ� �ִ´�
		}
	}

	void show() {//������ ������ ����Ѵ�.
		for_each(v.cbegin(), v.cend(), [&](int a) {
			cout << a << " ";
		});
		//������ ó������ ���������� ����Ѵ�.
	}
};
int main() {

	srand((unsigned int)time(NULL));//�õ尪 ����

	SelectableRandom a{ 1, 0, RAND_MAX };//Ȧ���� 0���� RAND_MAX������ ���� 10�� ����
	SelectableRandom b{ 0, 2, 10 };//¦���� 2���� 10������ ���� 10�� ����

	cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10��" << "--" << endl;

	a.show();//��ü a�� ���� ���

	cout << endl << endl;

	cout << "-- 2���� 10���� Ȧ�� ���� ���� 10�� --" << endl;

	b.show();//��ü b�� ���� ���
}