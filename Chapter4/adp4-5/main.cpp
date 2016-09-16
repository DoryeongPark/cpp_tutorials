#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
*	MyintStack
*	���� : ������ ������ �߻�ȭ �Ͽ���.
*/
class MyIntStack {
	vector<int> v;//������ �迭
public:
	MyIntStack() noexcept { v.reserve(10); }//10��ŭ ���� �̸� �Ҵ�
	//���� n�� push�Ѵ�.
	bool push(const int& n) noexcept {
		if (v.size() >= 10) {//�迭�� ���Ұ� 10���� ���
			return false;//�� �̻� ���� �� �����Ƿ� false ��ȯ
		}
		else {//�迭�� ���Ұ� 10�� �̸��� ���
			v.push_back(n);//���� n push
			return true;
		}		
	}
	//���� n�� pop�ϰ� �Ű������� ���� �����Ѵ�.
	bool pop(int& n) noexcept {
		if (v.size() <= 0) {//���� ����� 0�� ���
			return false;//�� �̻� ���Ҹ� �� �� ����
		}
		else {
			n = v.back();//���� �ڿ� �ִ� ���Ҹ� �Ű������� ����
			v.pop_back();//�ڿ� �ִ� ���� pop
			return true;//pop ���� 
		}
	}

};
int main() {
	MyIntStack a{};//������ ���� ��ü ����
	
	for (int i = 0; i < 11; ++i) {
		if (a.push(i))//���������� push�� ���
			cout << i << ' ';//push �� ���� ���
		else//�ƴ� ���
			cout << endl << i + 1 << "��° stack full" << endl;
			//������ ���� á���� �˸�
	}
	
	auto n = 0;//pop�� ������ �޾�� ����

	for (int j = 0; j < 11; ++j) {
		if (a.pop(n))//���������� pop�� ���
			cout << n << ' ';//pop�� ���� ���
		else
			cout << endl << j + 1 << "��° stack empty" << endl;
			//������ ��������� �˸�
	}
	
	cout << endl;
}