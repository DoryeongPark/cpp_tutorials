#include <iostream>	
#include <string>

using namespace std;

/*
*	Integer
*	������� : i - ����
*	���� : ������ �߻�ȭ�� Ŭ����
*/
class Integer {
private:
	int i;
public:
	Integer() noexcept : i(0) {}
	//����Ʈ ������ i�� ���� 0���� �ʱ�ȭ�Ѵ�.
	Integer(const int& _i) noexcept { i = _i; }
	//�Ű������� �ϳ��� ������ ������(�Ű����� ����)
	Integer(const string& _s) noexcept { i = stoi(_s); }
	//�Ű������� �ϳ��� ���ڿ��� ������(���� ��ȯ�� �� ����)
	int get() noexcept { return i; }
	//���� ������ ��ȯ�Ѵ�.
	void set(const int& _i)noexcept { i = _i; }
	//������ ������ �Ű������� �ٽ� set�Ѵ�.
	bool isEven() noexcept {//������ ������ ¦������ �ƴ��� ������ ��ȯ
		if (!(i % 2))
			return true;//¦���� ��� true ��ȯ
		else
			return false;//Ȧ���� ��� false ��ȯ
	}
};

int main() {
	Integer n{ 30 };//���� 30 Integer ��ü n ����
	cout << n.get() << ' ';//���� ���
	n.set(50);//��ü n�� ���� 50���� set
	cout << n.get() << ' ';//���� ���

	Integer m{ "300" };//���ڿ� 300�� �Ű������� Integer ��ü m ����
	cout << m.get() << ' ';//���� ���
	cout << m.isEven() << endl;//m�� ���� ������ Ȧ������ ¦������ ������ ���
}