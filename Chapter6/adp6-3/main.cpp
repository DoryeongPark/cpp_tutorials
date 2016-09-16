#include <iostream>
#include <string>	

using namespace std;
//Class Books
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
	//Shows memeber variables
	void show() noexcept {
		cout << title << " " << price << "��" << pages << "������" << endl;
	}
	//Title Getter
	auto getTitle() noexcept {
		return title;
	}
	//Operator function which Determines price is same and lower than 0 or not
	auto operator! () {
		if (price <= 0)
			return true;
		else
			return false;
	}
};

int main() {
	Book book{ "�������", 0, 50 };//Instantiates Book free

	if (!book)//If it is free
		cout << "��¥��" << endl;
}
