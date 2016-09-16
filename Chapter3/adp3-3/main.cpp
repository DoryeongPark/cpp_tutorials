#include <iostream>
#include <string>	
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>	

using namespace std;
/*
*	RandomString
*	���� : �Է¹��� ���ڿ��� �� ���ڰ� �����ϰ� �ٲ�� ���ڿ��̴�.
*	�߰� : ���鹮�ڴ� ���ڷ� �ٲ��� �ʰ� ó���Ͽ���. �׻� ���� ���ڿʹ� �ٸ� ���ڷ� �ٲ�� ó���Ͽ���.
*/
class RandomString {
	string replaced_string;//�ٲ� ���ڿ�

public:
	//������
	//��ü�� �������ڸ��� �Է¹޴´�.
	RandomString() noexcept {

		string input;//�Է��� ����
		vector<int>	space_index;//�Է��� ���ڿ��� ���鹮�ڵ��� �ε����� �����ϴ� ����

		cout << ">>";

		getline(cin, input, '\n');//���ڿ��� �Է¹޴´�.

		if (input == "exit")//�Է��� ���ڿ��� exit�� ���
			exit(0);//���α׷� ����

		int sp = 0;//���鹮�ڸ� ã�� start point

		while (input.find(' ', sp) != string::npos) {
			space_index.push_back(input.find(' ', sp));//���鹮���� �ε����� ���Ϳ� ����
			sp = input.find(' ', sp);//start point ����
			sp++;
		}

		auto random_index = -1;//���� ���ڸ� ������ �ε���
		
		while (random_index == -1) {
			random_index = rand() % input.size(); //���� ��ġ �ε��� ����
			//���� ������ ���� ��ġ �ε����� ���� ������ �ε����̸� find_if���� �����ϰ� �ٽ� ����
			find_if(space_index.begin(), space_index.end(), [&](auto index)->bool {
				if (random_index == index) {
					random_index = -1;//���ѷ��� ����
					return true;
				}
				return false;
			});
		}

		char ch = ' ';//���� ���� ����
		
		for(;;) {
			ch = rand() % 26 + 97;//���� ���� ����
			//������ �������ڰ� ���� �ε����� ���ڿ� �ٸ� ���
			if (input.at(random_index) != ch)
				break;//���ѷ��� Ż��
		}

		string random_ch{ ch };//�������ڸ� ���ڿ��� Wrapping
		//�ٲ� ���� ��ġ ���
		cout << random_index + 1 << "��° ���ڰ� �ٲ�����ϴ�." << endl;
		//���ڿ��� ���� �ε����� ���ڿ� ���� ���ڷ� ġȯ�Ѵ�.
		replaced_string = input.replace(random_index, 1 ,random_ch);
		//�ٲ� ���� ���
		cout << ">>" <<  replaced_string << endl;

		string arrow{};//ȭ��ǥ
		//�ٲ� �ε�����ŭ ���鹮�� ����
		for (int i = 0; i < random_index + 2; ++i) 
			arrow.append(" ");
		
		arrow.append("^");//�ٲ� ��ġ ȭ��ǥ�� ���
		
		cout << arrow << endl;//ȭ��ǥ ���
	}

};

int main() 
{
	srand((unsigned int)time(NULL));//�õ尪

	cout << "�Ʒ��� ������ �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)." << endl;

	for (;;) {
		RandomString s{};//���ڿ� �Է¹ް� �ٲ� ���ڿ� ���
	}
}
	
