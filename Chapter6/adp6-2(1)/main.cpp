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
		cout << title << " " << price << "원" << pages << "페이지" << endl;
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
	Book a{ "명품 C++", 30000, 500 };//Instantiates Book a
	Book b{ "고품 C++", 30000, 500 };//Instantiates Book b

	if (a == 30000)//If a's price is same as 30000
		cout << "정가 30000원" << endl;
	if (a == "명품 C++")//If b's name is same as "명품 C++"
		cout << "명품 C++ 입니다." << endl;
	if (a == b)//If a and b are same
		cout << "두 책이 같은 책입니다." << endl;
}