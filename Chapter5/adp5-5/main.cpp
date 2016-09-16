#include <iostream>
#include <algorithm>
#include <vector>	

using namespace std;

//Function 1 : Converts components of vector a into real number and stores them into vector b
auto f1 = [](const vector<int>& a, vector<double>& b, const int& size) {
	b.clear();//clear vector b
	for (int i = 0; i < size; ++i)
		b.push_back(static_cast<double>(a[i]));//Stores converted value in b
};
//Function 1 : Converts components of vector a into integer number and stores them into vector b
auto f2 = [](const vector<double>& a, vector<int>& b, const int& size) {
	b.clear();//clear vector b
	for (int i = 0; i < size; ++i)
		b.push_back(static_cast<int>(a[i]));//Stores converted value in b
};

class ArrayUtility {
public:
	//static member functions
	static decltype(f1) intToDouble;
	static decltype(f2) doubleToInt;
};
//Initializes static members 
decltype(f1) ArrayUtility::intToDouble = f1;
decltype(f2) ArrayUtility::doubleToInt = f2;

int main() {
	vector<int> x = { 1, 2, 3, 4, 5 };//vector x
	vector<double> y;//vector y
	vector<double> z = { 9.9, 8.8, 7.7, 6.6, 5.6 };//vector z
	//Converts x's values into real numbers then stores 5 of them in y
	ArrayUtility::intToDouble(x, y, 5);
	//Prints y's values
	for_each(y.cbegin(), y.cend(), [&](double a) {
		cout << a << ' ';
	});

	cout << endl;
	//Converts z's values into integer numbers then stores 5 of them in x
	ArrayUtility::doubleToInt(z, x, 5);
	//Prints x's values
	for_each(x.cbegin(), x.cend(), [&](int a) {
		cout << a << ' ';
	});

	cout << endl;
}