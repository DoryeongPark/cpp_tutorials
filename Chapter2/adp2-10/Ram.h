#pragma once

#include <iostream>

//Ram Ŭ���� ����� 
class Ram
{
	char mem[100 * 1024] = { 0, };//�޸𸮸� ǥ���� �迭, ���� 0���� ��� �ʱ�ȭ
	int size;
public:
	Ram() noexcept;//������
	~Ram() noexcept;//�Ҹ���
	char read(const int& address) noexcept;//�޸� �ּҿ� �ִ� �� ��ȯ
	void write(const int& address, const char& value) noexcept;//�ش� �޸� �ּҿ� �ش� ���� ����
};
