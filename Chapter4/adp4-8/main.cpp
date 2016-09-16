#include <iostream>	
#include <cstring>

using namespace std;
/*
*	Book
*	설명 : 책을 추상화한 클래스, C++의 Classic한 Expression 사용
*/
class Book {
	char* title = nullptr;//책 이름
	int price;//책 가격
public:
	Book() noexcept;//기본 생성자
	Book(const char* title, const int& price) noexcept;//Member Setter 생성자
	~Book();//소멸자
	Book(Book& b);//복사 생성자
	void set(const char* title, const int& price) noexcept;//Class Member Setter
	void show() noexcept;//책의 내용 출력
};

Book::Book() noexcept : price(0) {}//price의 default값 : 0
//Member Setter 생성자
Book::Book(const char* title, const int& price) noexcept {
	this->title = new char[strlen(title) + 1];//매개변수의 크기만큼 문자형 배열 동적생성
	strcpy_s(this->title, strlen(title)+1, title);//매개변수의 문자열 복사
	this->price = price;//매개변수의 price 복사
}
//소멸자
Book::~Book() {
	delete[] title; //동적 생성된 메모리 해제
}

/* 컴파일러가 생성하는 default 복사 생성자 */
/*
Book::Book(Book& b) {
	title = b.title;
	price = b.price;
}
*/
//깊은 복사 생성자
Book::Book(Book& b){
	//복사할 객체의 책 제목 문자열 크기만큼 문자형 배열 동적생성
	this->title = new char[strlen(b.title) + 1];
	strcpy_s(this->title,strlen(b.title) + 1,b.title);//복사할 객체의 책 제목 복사
	this->price = b.price;//복사할 객체의 가격 복사
}

//Member Setter
void Book::set(const char* title, const int& price) noexcept {
	delete[] this->title;//현재 문자열 메모리를 해제한다.
	this->title = new char[strlen(title) + 1];//매개변수 크기만큼 문자형 배열 동적 생성
	strcpy_s(this->title, strlen(title) + 1, title);//매개변수 문자열 복사
	this->price = price;//매개변수 가격 복사
}
//현재 책 제목과 가격 출력
void Book::show() noexcept {
	cout << title << " " << price << "원" << endl;
}

int main() {
	Book cpp{ "명품C++", 10000 };//책 제목 명품C++ , 가격 10000인 책 생성
	Book java = cpp;//현재 책 Book 객체 java에 복사
	java.set("명품자바", 12000);//객체 java의 내용을 바꾼다.
	cpp.show();//cpp의 내용 출력
	java.show();//java의 내용 출력
}