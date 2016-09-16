#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

//������׷� Ŭ���� ����
class Histogram {
	std::string s;//�м��� ���ڿ�
	std::map<char, int> analyzer;//���ڿ� �м� map<char, int>
public:
	Histogram() = default;//����Ʈ ������
	Histogram(const std::string& input) noexcept;//�Ű������� ���ڿ��� ������
	Histogram(const char& input) noexcept;//�Ű������� ������ ������
	void put(const std::string& input) noexcept;//���ڿ� �߰�
	void putc(const char& input)noexcept;//���� �߰�
	void initialize_analyzer() noexcept;//��� �ε����� 0���� �ʱ�ȭ
	void update_analyzer()noexcept;//���ŵ� ���ڿ��� ������� �м�
	void print()noexcept;//���ڿ� ������׷� ���
};

