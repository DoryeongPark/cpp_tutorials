#include <iostream>
#include <string>

using namespace std;

int main() {
	//�Լ� find(���ڿ�, ã�� ����, ã�� ���� Flag)
	auto find = [&](string& a, const char& c, bool& success) ->char&{
		if (a.find_first_of(c) != string::npos) {//���ڿ����� �ش� ���ڸ� ã���� ���
			success = true;//Flag�� true�� �ٲ۴�.
			return a.at(a.find_first_of(c));//�ش� �ε����� ���� ������ return
		}
	};

	string s = "Mike";//���� ���ڿ�
	bool b = false;//�÷��װ� �ʱ� ����
	char &loc = find(s, 'M', b);//�ش� ���ڰ� ������ ��� ���� ��ȯ �� b = true

	if (b == false) {//�÷��װ� true �ٲ��� �ʾ��� ���
		cout << "M�� �߰��� �� ����." << endl;//���� ���
		exit(0);//����
	}

	loc = 'm';//������ �̿��Ͽ� string s���� ���� �ٲ۴�.
	cout << s << endl;//�ٲ� ���� Ȯ���ϱ� ���� ���� ���ڿ� ��� 
}