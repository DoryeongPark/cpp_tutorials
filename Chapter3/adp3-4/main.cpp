#include <iostream>
#include <string>

using namespace std;

/*
*	ReverseString
*	���� : �Է��� ���ڿ��� �Ųٷ� ��µǴ� ���ڿ�
*/
class ReverseString {
	string reverse_string;//�Ųٷ� ��µǴ� ���ڿ�

public:
	//�������ڸ��� ���ڿ��� �Է¹޴´�.
	ReverseString() noexcept{
		cout << ">>";
		//���ڿ��� �Է¹޴´�.
		getline(cin, reverse_string, '\n');
		//���� �Է¹��� ���ڿ��� exit�� ���
		if (reverse_string == "exit")
			exit(0);//���α׷� ����
		//�Է¹��� ���ڿ��� ������ �Ųٷ� �ٲ۴�.
		reverse(reverse_string.begin(), reverse_string.end());
	}
	
	//�ٲ� ���ڿ� ��ȯ
	string get_string() noexcept {
		return reverse_string;
	}
};
int main() {
	cout << "�Ʒ��� ������ �Է��ϼ���. (exit�� �Է��ϸ� �����մϴ�.)" << endl;

	for (;;) {
		ReverseString r{};//���ڿ��� �Է¹ް� ���ڿ��� ������ �ٲ۴�.
		cout << r.get_string() << endl;//������ �ٲ� ���ڿ� ���
	}
}