#include <iostream>
#include <string>	

using namespace std;

//Class Book
class Book {
	string title;//Book title
	int price;//Book price
	int pages;//Book pages
public:
	//Book Setter
	Book(const string& _title = "", const int& _price = 0, 
		const int& _pages = 0) noexcept{
		title = _title;//Set title
		price = _price;//Set price
		pages = _pages;//Set pages
	}
	//Shows member variables
	void show() noexcept {
		cout << title << " " << price << "원" << pages << "페이지" << endl;
	}
	//Title Getter
	string& getTitle() noexcept{
		return title;
	}
	//Increases price by a
	Book& operator +=(const int& a) {
		price += a;
		return *this;
	}
	//Decreases price by a
	Book& operator -=(const int& a) {
		price -= a;
		return *this;
	}
};
int main() {

	Book a{ "청춘", 20000, 300 };//Instantiates Book a
	Book b{ "미래", 30000, 500 };//Instantiates Book b

	a += 500;//Increases a's price by 500.
	b -= 500;//Increases b's price by 500.

	a.show();//Prints a's members.
	b.show();//Prints b's members.
}