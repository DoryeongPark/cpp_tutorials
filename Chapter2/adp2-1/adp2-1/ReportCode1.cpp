#include <iostream>	

using namespace std;

/*
*	Tower
*	������� : height - Ÿ���� ����
*	���� : Ÿ���� �߻�ȭ�� Ŭ����
*/
class Tower {
private:
	int height;
public:
	Tower() noexcept : height(1) {} //����Ʈ ������ - ������ �ʱⰪ : 1
	Tower(const int& _height) noexcept { height = _height; }//������ - �Ű������� ���� �ʱ�ȭ
	int getHeight() noexcept {//��ü�� ������ �ִ� ���� ���� ��ȯ
		return height;
	}
};

int main() {
	Tower myTower;//ž ��ü ����(���� : 1)
	Tower seoulTower{ 100 };//���̰� 100�� ž ��ü ����

	cout << "���̴� " << myTower.getHeight() << "����" << endl;//ù ��° ������ ���̰� ���
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;//�� ��° ������ ���̰� ���

}