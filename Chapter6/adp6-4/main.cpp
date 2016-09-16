#include <iostream>
#include <string>	
#include <cstring>

using namespace std;
//Class Book
class Book {
	string title;//Book title
	int price;//Book price
	int pages;//Book pages
public:
	//Getter Constructor
	Book(const string& _title = "", const int& _price = 0,
		const int& _pages = 0) noexcept {
		title = _title;
		price = _price;
		pages = _pages;
	}
	//Prints member variables
	void show() noexcept {
		cout << title << " " << price << "��" << pages << "������" << endl;
	}
	//Title Getter
	auto getTitle() noexcept {
		return title;
	}
	//Determines title is less than parameter or not
	auto operator < (const string& s) {
		if (strcmp(title.c_str(), s.c_str()) == 1)
			return true;
		else
			return false;
	}
};

int main() {
	Book a{ "û��", 20000, 300 };//Instantiates Book a
	string b;//Input string
	cout << "å �̸��� �Է��ϼ��� >> ";
	getline(cin, b);

	//if string input is greater than a's title
	if (a < b)
		cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���." << endl;
}