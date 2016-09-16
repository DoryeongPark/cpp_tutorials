#include <iostream>
#include <string>	

using namespace std;

//Class Book
class Book {
	string title;//Book title
	int price;//Book price
	int pages;//Book pages
public:
	//Book Setter Constructor
	Book(const string& _title = "", const int& _price = 0,
		const int& _pages = 0) noexcept {
		title = _title;//Set book's title
		price = _price;//Set book's price
		pages = _pages;//Set book's pages
	}
	//Shows member variables
	void show() noexcept {
		cout << title << " " << price << "원" << pages << "페이지" << endl;
	}
	//Title Getter
	string& getTitle() noexcept {
		return title;
	}
	//Declares operator functions
	friend Book& operator += (Book& b, const int& a);
	friend Book& operator -= (Book& b, const int& a);
};
//Function which increases book's price by a
Book& operator += (Book& b, const int& a) {
	b.price += a;
	return b;
}
//Function which decreases book's price by a
Book& operator -= (Book& b, const int& a) {
	b.price -= a;
	return b;
}

int main() {
	Book a{ "청춘", 20000, 300 };//Instantiates Book a
	Book b{ "미래", 30000, 500 };//Instantiates Book b

	a += 500;//Increases a's price by 500
	b -= 500;//Decreases b's price by 500
	//Shows members
	a.show();
	b.show();
}