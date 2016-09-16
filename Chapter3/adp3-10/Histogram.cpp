#include "Histogram.h"

//������׷� Ŭ���� ����
using namespace std;
//���ڿ��� �Ű������� �ϴ� ������
Histogram::Histogram(const string& input)noexcept {
	initialize_analyzer();//map �ʱ�ȭ
	s = input;//���ڿ� ����
	update_analyzer();//���ڿ��� �м��Ͽ� map ����
}
//���ڸ� �Ű������� �ϴ� ������
Histogram::Histogram(const char& input) noexcept {
	initialize_analyzer();//map �ʱ�ȭ
	s.append(1, input);//���� ����
	update_analyzer();//���ڿ��� �м��Ͽ� map ����
}
//���ڿ� �߰�
void Histogram::put(const string& input) noexcept {
	s.append(input);//��������� ���ڿ��� �߰��Ѵ�.
	update_analyzer();//���ŵ� ���ڿ��� �м��Ѵ�.
}
//���� �߰�
void Histogram::putc(const char& input) noexcept {
	s.append(1, input);//��������� ���ڸ� �߰��Ѵ�.
	update_analyzer();//���ŵ� ���ڿ��� �м��Ѵ�.
}
//map�� key(a ~ z)�� value���� 0���� �ʱ�ȭ�Ѵ�.
void Histogram::initialize_analyzer() noexcept {
	for (char c = 97; c <= 122; c++)//a ~ z
		analyzer[c] = 0;//0���� �ʱ�ȭ
}
//���ŵ� ���ڿ��� map�� �м��Ѵ�.
void Histogram::update_analyzer() noexcept {

	analyzer.clear();//������ map�� �����.
	
	initialize_analyzer();//map �ʱ�ȭ setting

	for (auto c : s) {//���ο� ���ڿ�
		if((c >= 97 && c <= 122) || (c >= 65 && c <= 90))//�ҹ��ڳ� �빮���� ���
			analyzer[tolower(c)] += 1;//�ش� value�� 1 ������Ų��.
	}
}
//���� map�� ������ ������׷����� ǥ���Ѵ�.
void Histogram::print() noexcept {

	cout << s << endl;//���� ���ڿ� ���
	
	int accum = 0;//���� ���ĺ��� ����

	for (char c = 97; c <= 122; ++c)
		accum += analyzer[c];//������ ������Ų��.

	cout << "�� ���ĺ� �� : " << accum << endl;//���ĺ��� ���� ���
	
	for (auto kv : analyzer) {//analyzer �ݺ���
		string star;//�� ���ڿ�
		star.append(kv.second, '*');//�ش� ���ĺ�(Key)�� ����(Value)��ŭ ���� �߰��Ѵ�.
		cout << kv.first << " (" << kv.second << ") : " << star << endl;//�ش� ���ĺ�(Key)�� ���� ����(Value) ���
	}
}