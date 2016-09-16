#include <iostream>	
#include <memory>
#include <algorithm>

using namespace std;

class MyIntStack {
	unique_ptr<int> p;//�迭 ������ 
	int size;//�迭 ������
	int top = -1;//���� ���� �ڿ� �ִ� ������ �ε���

public:
	MyIntStack() = default;//�⺻ ������(default)
	
	//�����ŭ �迭�� ���� �����Ѵ�.
	explicit MyIntStack(const int& size) noexcept:size(size){
		p.reset(new int[size]);
	}
	//���� ������
	MyIntStack(MyIntStack& s) {
		p.reset(new int[s.size]);//������ ��ü�� �迭 �����ŭ �迭 ����
		top = s.top; size = s.size;//������ ��ü�� top, size ����
		for (int i = 0; i < s.size; ++i)//�迭�� ���� ����
			i[p.get()] = s.at(i);
	}
	//����Ʈ �����Ͱ� �˾Ƽ� �޸� ����(�Ҹ��� �ʿ����)
	~MyIntStack() = default;

	int at(const int& n) noexcept{//���� �迭�� ���� ��ȯ
		return n[p.get()];
	}
	//���� n�� �迭�� push�Ѵ�.
	bool push(const int& n) noexcept {
		if (top >= 9) {//top�� ����Ű�� �ִ� �ε����� 9�̸� 10���� ��� ���ִ� ����
			return false;//push �Ұ�
		}
		else {
			(++top)[p.get()] = n;//���� push �� top����
			return true;
		}
	}
	//���Ҹ� pop�ϰ� pop�� ���Ҹ� �Ű������� ����
	bool pop(int& n) noexcept {
		if (top <= -1) {//����Ű�� �ִ� �ε����� -1��� ���� ���Ұ� ���� ����
			return false;//pop �Ұ�
		}
		else {
			n = top[p.get()];//����Ű�� �մ� ���Ҹ� �Ű������� ����
			//���Ұ� ���� ���� NULL �����ͷ� ����� ����
			(top--)[p.get()] = static_cast<int>(NULL);
			return true;
		}
	}
};
int main() {
	MyIntStack a{ 10 };//10�������� ���� ����
	a.push(10);//10 push
	a.push(20);//20 push

	MyIntStack b = a;//10, 20 push�� ���� ���� b�� ����
	b.push(30);//b�� 30 push

	int n;
	a.pop(n);//a���� pop
	cout << "���� a���� ���� �� : " << n << endl;//pop�� �� Ȯ��
	b.pop(n);//b���� pop
	cout << "���� b���� ���� �� : " << n << endl;//pop�� �� Ȯ��
}