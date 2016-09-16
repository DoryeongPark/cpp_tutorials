#include <iostream>
#include <functional>

using namespace std;

int main() {
	//Functor big
	struct big {
		big() = default;
		//Function1 : Determines bigger value between a and b. Then determines smaller one between the value and c.
		int operator()(const int& a, const int& b, const int& c) {
			return (a > b ? a : b) > c ? c : (a > b ? a : b);
		}
		//Function2 : Determines bigger value between a and b. Then determines smaller one between the value and 100.
		int operator()(const int& a, const int& b) {
			return (a > b ? a : b) > 100 ? 100 : (a > b ? a : b);
		}
	};
	//Gets values from each functions
	int x = big{}(3, 5);
	int y = big{}(300, 60);
	int z = big{}(30, 60, 50);
	//Prints values
	cout << x << " " << y << " " << z << endl;
}