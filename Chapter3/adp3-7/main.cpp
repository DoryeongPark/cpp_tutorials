#include <iostream>	
#include <string>

using namespace std;

/*
*	Person
*	���� : ����� ������ �߻�ȭ�� Ŭ����
*/
class Person {
	string name;//�̸�
	string tel;//��ȭ��ȣ
	int num;//��ȣ
protected:
	static int person_num;//��ȣ �Ҵ�� Ŭ���� ����
public:
	//�������ڸ��� ������ �Է¹޴´�.
	Person() noexcept{

		num = ++person_num;//��ȣ�� �Ҵ� �ް� ����

		string input;//�Է��� ���ڿ�

		cout << "��� " << num << ">> ";

		getline(cin, input, '\n');//���ڿ��� �Է¹޴´�

		name = input.substr(0, input.find(' ', 0));//������ �����ڷ� ù ��° string ����(name)
		tel = input.substr(input.find(' ', 0) + 1, 
			(input.find(' ', input.find(' ', 0) + 1)) - 
			(input.find(' ', 0) + 1));//������ �����ڷ� �� ��° string ����(tel)
	}
	//�̸� ��ȯ
	string getName() noexcept {
		return name;
	}
	//��ȭ��ȣ ��ȯ
	string getTel() noexcept {
		return tel;
	}
};

int Person::person_num = 0;
using namespace std;

int main() {

	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���." << endl;
	
	Person* p_arr = new Person[3];//Person ��ü �迭 ����

	cout << "��� ����� �̸��� " << endl;
	//�迭 ���� �� Person�� �̸� ���
	for (int i = 0; i < 3; ++i) 
		cout << i[p_arr].getName() << endl;
	

	string name_input;//�˻��� �̸�

	cout << "��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ��� >> ";

	getline(cin, name_input, '\n');//�˻��� �̸� �Է�

	//�ݺ����� �̿��Ͽ� �˻��� �̸��� ���ʷ� ���Ѵ�.
	for (int i = 0; i < 3; ++i) {
		if (name_input == i[p_arr].getName())//�˻��� �̸��� ����� �̸��� ���� ���
			cout << "��ȭ��ȣ�� " << p_arr[i].getTel() << endl;//�ش� ����� ��ȭ��ȣ ���
	}

	delete[] p_arr;//Circle��ü �迭 �޸� ���� 
}
