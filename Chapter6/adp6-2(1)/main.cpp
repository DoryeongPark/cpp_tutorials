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
	//Title getter
	auto getTitle() noexcept {
		return title;
	}
	//Operator function determines Book's price and parameter are same or not.
	auto operator == (const int& a) {
		if (a == price)
			return true;
		else
			return false;
	}
	//Operator function determines Book's title and parameter are same or not.
	auto operator == (const string& s) {
		if (title == s)
			return true;
		else
			return false;
	}
	//Operator function determines Books are same or not.
	auto operator == (Book& b) {
		if (title == b.title && price == b.price &&
			pages == b.pages)//If all of members are same..
			return true;
		else
			return false;
	}
};

int main() {
	Book a{ "��ǰ C++", 30000, 500 };//Instantiates Book a
	Book b{ "��ǰ C++", 30000, 500 };//Instantiates Book b

	if (a == 30000)//If a's price is same as 30000
		cout << "���� 30000��" << endl;
	if (a == "��ǰ C++")//If b's name is same as "��ǰ C++"
		cout << "��ǰ C++ �Դϴ�." << endl;
	if (a == b)//If a and b are same
		cout << "�� å�� ���� å�Դϴ�." << endl;
}