#include <iostream>	
#include <string>

using namespace std;

int main() {

	//�Լ� bigger : �� ���� ���Ͽ� ū ���� 3��° �Ű������� ����
	auto bigger = [&](int a, int b, int& big)->bool {
		if (a > b) {//a�� �� ū ���
			big = a;//big�� a ����
			return false;
		}
		else if (a < b) {//b�� �� ū ���
			big = b;//big�� b ����
			return false;
		}
		else {
			return true;//�� ���� ���� ��� true ��ȯ
		}
	};
	
	string input1{};//����1
	string input2{};//����2
	
	cout << "Input \"exit\" to finish." << endl;

	while(true) {
		auto big = 0;//ū ���� ���� ����

		cout << "���� 1 >> ";
		getline(cin, input1, '\n');//����1 �Է�
		cout << "���� 2 >> ";
		getline(cin, input2, '\n');//����2 �Է�
		//�ϳ��� exit �Է� �� ����
		if (input1 == "exit" || input2 == "exit")
			exit(0);

		//�Է� ����ó��
		try {
			if (!bigger(stoi(input1), stoi(input2), big))//�� ���� �ٸ� ���
				cout << "ū ��: " << big << endl;//ū �� ���
			else//�� ���� ���� ���
				cout << "�� ���� �����ϴ�." << endl;
		}
		catch (exception e) {//�Է� ���ܰ� �߻��� ���
			cout << e.what() << endl;//���� ���
		}
	}
}