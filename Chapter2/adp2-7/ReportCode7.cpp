#include <iostream>

using namespace std;

/*
*	Oval
*	������� : width - ���� / height - ����
*	���� : Ÿ���� �߻�ȭ�� Ŭ����
*/
class Oval {
private:
	int width;
	int height;

public:
	Oval()noexcept : width(1), height(1) {} //����Ʈ ������ �ʱⰪ width = 1, height = 1
											//������ �Ű����� 2��(width, height)�� �޴� ������
	Oval(const int& _width, const int& _height)noexcept {
		width = _width;
		height = _height;
	}
	//�Ҹ��� - ������ ���� ������ ����ϰ� ��ü�� �Ҹ�ȴ�.
	~Oval() { cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl; }
	int getWidth()noexcept { return width; }	// ���� ��ȯ
	int getHeight()noexcept { return height; } // ���� ��ȯ
	void set(const int& w, const int& h)noexcept { width = w; height = h; }//���ο� ������ ���� set�Ѵ�
	void show()noexcept {//���ο� ������ �� ���
		cout << "width = " << width << " height = " << height << endl;
	}
};

int main() {
	Oval a, b{ 3, 4 };//Oval��ü a ����, width = 3, height = 4�� Oval��ü b ����
	a.set(10, 20);//��ü a�� width = 10, height = 20�� set�Ѵ�.
	a.show();//a�� ���� ���
	cout << b.getWidth() << ", " << b.getHeight() << endl;//b�� ���ο� ���� ���� ���� ���
}