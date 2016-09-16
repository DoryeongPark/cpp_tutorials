#include <iostream>

using namespace std;

/*
*	Color 
*	������ ��Ÿ���� RGB ���� �߻�ȭ�� Ŭ����
*/
class Color {
private:
	int red;//R channel
	int green;//G channel
	int blue;//B channel
public:
	//��� �������� default�� ����
	Color() noexcept : red(0), green(0), blue(0) {}

	//������ �Ű������� �ϴ� ������(0 : Red, 1 : Green, 2 : Blue)
	Color(const int& channel) {
		if (channel == 0) {//�Ű����� 0�� ���
			red = 255; green = 0; blue = 0;
		}
		else if (channel == 1) {//�Ű����� 1�� ���
			red = 0; green = 255; blue = 0;
		}
		else if (channel == 2){//�Ű����� �������� ���
			red = 0; green = 0; blue = 255;
		}
		else {
			red = 0; green = 0; blue = 0;
		}
			
	}
	//RGB ������ ���� �Ű������� �޴� ������
	Color(const int& r, const int& g, const int& b) noexcept {
		red = r;
		green = g;
		blue = b;
	}

	~Color() = default;//default �Ҹ���
	//���� ��ü�� RGB���� �Ű������� set�Ѵ�.
	void setColor(const int& r, const int& g, const int& b) noexcept {
		red = r;
		green = g;
		blue = b;
	}
	//���� ����������� ������ �ܼ�â�� ���
	void show() noexcept {
		cout << red << ' ' << green << ' ' << blue << endl;
	}

};

int main() {

	Color screenColor{ 255, 0, 0 };
	Color *p;

	//1. p�� screenColor�� �ּҸ� �������� �ڵ� �ۼ�
	p = &screenColor;

	//2. p�� show()�� �̿��Ͽ� screenColor �� ���
	p->show();

	//3. Color�� ������ �迭 colors ����, ���Ҵ� 3��
	Color* colors = new Color[3];
	
	//4. p�� colors �迭�� ����Ű���� �ڵ� �ۼ�
	p = colors;

	//5. p�� setColor�� �̿��Ͽ� colors[0], colors[1], colors[2]��
	//���� ���� �ʷ� �Ķ����� �������� �ڵ� �ۼ�
	for (int i = 0; i < 3; ++i)
		i[colors] = Color{ i };

	//6. show()�� �̿��Ͽ� colors �迭�� ��� ��ü�ǻ� ��� for�� ���
	for (int i = 0; i < 3; ++i)
		colors[i].show();

	delete[] colors;//�޸� ����
}