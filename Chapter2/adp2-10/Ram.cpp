#include "Ram.h"	
using namespace std;

//Ram Ŭ������ �Լ� ���Ǻ�
Ram::Ram() noexcept :size(100 * 1024) {//size default�� 100*1024
}

Ram::~Ram() noexcept {//�Ҹ��� 
	cout << "�޸� ���ŵ�" << endl;//�Ҹ�Ǹ鼭 ���� ���
}

char Ram::read(const int& address)noexcept {
	return mem[address];//�Ű����� �ּ��� �迭 ������ ���� ��ȯ
}

void Ram::write(const int& address, const char& value) noexcept {
	mem[address] = value;//�Ű����� �ּ��� �迭���ҿ� �Ű����� ���� �����Ѵ�.
}