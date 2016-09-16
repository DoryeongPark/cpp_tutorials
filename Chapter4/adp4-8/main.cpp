#include <iostream>	
#include <cstring>

using namespace std;
/*
*	Book
*	���� : å�� �߻�ȭ�� Ŭ����, C++�� Classic�� Expression ���
*/
class Book {
	char* title = nullptr;//å �̸�
	int price;//å ����
public:
	Book() noexcept;//�⺻ ������
	Book(const char* title, const int& price) noexcept;//Member Setter ������
	~Book();//�Ҹ���
	Book(Book& b);//���� ������
	void set(const char* title, const int& price) noexcept;//Class Member Setter
	void show() noexcept;//å�� ���� ���
};

Book::Book() noexcept : price(0) {}//price�� default�� : 0
//Member Setter ������
Book::Book(const char* title, const int& price) noexcept {
	this->title = new char[strlen(title) + 1];//�Ű������� ũ�⸸ŭ ������ �迭 ��������
	strcpy_s(this->title, strlen(title)+1, title);//�Ű������� ���ڿ� ����
	this->price = price;//�Ű������� price ����
}
//�Ҹ���
Book::~Book() {
	delete[] title; //���� ������ �޸� ����
}

/* �����Ϸ��� �����ϴ� default ���� ������ */
/*
Book::Book(Book& b) {
	title = b.title;
	price = b.price;
}
*/
//���� ���� ������
Book::Book(Book& b){
	//������ ��ü�� å ���� ���ڿ� ũ�⸸ŭ ������ �迭 ��������
	this->title = new char[strlen(b.title) + 1];
	strcpy_s(this->title,strlen(b.title) + 1,b.title);//������ ��ü�� å ���� ����
	this->price = b.price;//������ ��ü�� ���� ����
}

//Member Setter
void Book::set(const char* title, const int& price) noexcept {
	delete[] this->title;//���� ���ڿ� �޸𸮸� �����Ѵ�.
	this->title = new char[strlen(title) + 1];//�Ű����� ũ�⸸ŭ ������ �迭 ���� ����
	strcpy_s(this->title, strlen(title) + 1, title);//�Ű����� ���ڿ� ����
	this->price = price;//�Ű����� ���� ����
}
//���� å ����� ���� ���
void Book::show() noexcept {
	cout << title << " " << price << "��" << endl;
}

int main() {
	Book cpp{ "��ǰC++", 10000 };//å ���� ��ǰC++ , ���� 10000�� å ����
	Book java = cpp;//���� å Book ��ü java�� ����
	java.set("��ǰ�ڹ�", 12000);//��ü java�� ������ �ٲ۴�.
	cpp.show();//cpp�� ���� ���
	java.show();//java�� ���� ���
}