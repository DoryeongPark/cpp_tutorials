#include "Calculator.h"

using namespace std;

//Calculator Ŭ������ setValue �Լ� ����
//�Ű����� : a - ����1 / b - ����2
void Calculator::setValue(const int& _a, const int& _b) {
	a = _a; b = _b;//����1�� ����2�� �Ű������� �޾� ����
}

int Add::calculate() { return a + b; }
//Add Ŭ������ calculate�Լ� ����(�� ������ ������ ��ȯ)
int Sub::calculate() { return a - b; }
//Add Ŭ������ calculate�Լ� ����(�� ������ ������ ��ȯ)
int Mul::calculate() { return a * b; }
//Add Ŭ������ calculate�Լ� ����(�� ������ ������ ��ȯ)
int Div::calculate() { return a / b; }
//Add Ŭ������ calculate�Լ� ����(�� ������ ������ ��ȯ)

int main() {
	Add a; Sub s; Mul m; Div d;
	//Add ��ü a, Sub ��ü s, Mul ��ü m, Div ��ü d�� ����
	int value1, value2;//������ ���� 2�� ����
	char oper;//�����ڸ� ���� ���� ����

	for (;;) {
		cout << "�� ������ �����ڸ� �Է��ϼ��� >>";
		cin >> value1 >> value2 >> oper;
		//����1, ����2, �����ڸ� �Է¹޴´�.
		if (oper == '+') {//�����ڰ� +�� ���
			a.setValue(value1, value2);//�Է��� ������� Add��ü�� Set
			cout << a.calculate() << endl;//����� �� ���
		}
		else if (oper == '-') {//�����ڰ� -�� ���
			s.setValue(value1, value2);//�Է��� ������� Sub��ü�� Set
			cout << s.calculate() << endl;//����� �� ���
		}
		else if (oper == '*') {//�����ڰ� *�� ���
			m.setValue(value1, value2);//�Է��� ������� Mul��ü�� Set
			cout << m.calculate() << endl;//����� �� ���
		}
		else if (oper == '/') {//�����ڰ� /�� ���
			d.setValue(value1, value2);//�Է��� ������� Div��ü�� Set
			cout << d.calculate() << endl;//����� �� ���
		}
		else {//�����ڰ� �������� ���
			cout << "default" << endl;
		}
	}
}