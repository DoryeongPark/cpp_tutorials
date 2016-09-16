#include <iostream>
#include <string>	

using namespace std;

//Class Book
class Book {
	string title;//Book title
	int price;//Book price
	int pages;//Book pages
public:
	//Setter Constructor
	Book(const string& _title = "", const int& _price = 0,
		const int& _pages = 0) noexcept {
		title = _title;
		price = _price;
		pages = _pages;
	}
	//Shows member variables
	void show() noexcept {
		cout << title << " " << price << "��" << pages << "������" << endl;
	}
	//Title Getter
	auto getTitle() noexcept {
		return title;
	}
	//Declares friend operator functions
	friend auto operator == (const Book& b, const int& a);
	friend auto operator == (const Book& b, const string& s);
	friend auto operator == (const Book& a, const Book& b);
};
//Operator function determines Book's price and parameter are same or not.
auto operator == (const Book& b, const int& a) {
	if (a == b.price)
		return true;
	else
		return false;
}
//Operator function determines Book's title and parameter are same or not.
auto operator == (const Book& b, const string& s) {
	if (b.title == s)
		return true;
	else
		return false;
}
//Operator function determines Books are same or not.
auto operator == (const Book& a, const Book& b) {
	if (a.title == b.title && a.price == b.price &&
		a.pages == b.pages)//If all of members are same
		return true;
	else
		return false;
}

int main() {
	Book a{ "��ǰ C++", 30000, 500 };//Instantiates Book a
	Book b{ "��ǰ C++", 30000, 500 };//Instantiates Book b

	if (a == 30000)//Determines a's price is same as 30000
		cout << "���� 30000��" << endl;
	if (a == "��ǰ C++")//Determines a's title is same as "��ǰ C++"
		cout << "��ǰ C++ �Դϴ�." << endl;
	if (a == b)//Determines a and b are same
		cout << "�� å�� ���� å�Դϴ�." << endl;
}