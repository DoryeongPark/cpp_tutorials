#include "tokenizer.h"
#include <algorithm>
//�߰� : ��� �Է� ���� ó��
using namespace std;

class Sample {
	vector<int>* v;//������ �迭 ������
	int size;//�迭�� ������ �ִ� ���� ��
public:
	//������
	Sample(const int& n)noexcept : size(n), v(new vector<int>) { v->reserve(n); }
	//���� �Ҵ� ���� ���� �迭(����)�� p�� ����ڷκ��� ������ �Է�, �Է¹��� ������ ��ŭ ���� �̸� �Ҵ�
	void read(){
		string input;
		getline(cin, input, '\n');//���ڿ��� �Է¹޴´�.

		try {//���� �˻�
			tokenize(input, *v);//���ڿ��� ������ �����ڷ� ������ ������ �迭�� ����
		}
		catch (...) {//�Է��� �� �� ������ �ƴ� ���� ���� ��� ���� ����
			cout << "������ �Է��ϼ���." << endl;//���� ó��
		}
	}
	//���� �迭�� ȭ�鿡 ���
	void write() noexcept{
		//�ݺ����� ����Ͽ� ������ �迭�� ���� ���
		for_each(v->cbegin(), v->cend(), [&](int i){
			cout << i << ' ' ;
		});
		cout << endl;
	}
	//���� �迭���� ���� ū �� ����
	int big() noexcept {
		auto max = 0;//���� ū ���� ���� ���� ����
		for (auto i : *v) {
			if (i > max)//���� �迭���� ���� ������ ���� ���� ū ������ Ŭ ���
				max = i;//�� ���� ���� ū ���� �����Ѵ�.
		}
		return max;//���� ū �� ��ȯ
	};
	//�Ҹ���
	~Sample() { delete v; }//Sample ��ü�� �Ҹ��� �� ���� �Ҹ�
	//�����̹Ƿ� �����Ͱ� ����Ű�� �͸� �Ҹ� ([] �߰� ���ص� ��)
};

int main() {
	Sample s{ 10 };//������ 10�� �̸� �Ҵ���� Sample ��ü ����
	s.read();//�Է¹��� �������� �д´�.
	s.write();//�о���� �������� ����Ѵ�.
	cout << "���� ū ���� " << s.big() << endl;//���� ū �� ���
}