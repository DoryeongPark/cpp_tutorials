#include <iostream>

using namespace std;

int main() {
	//Determines bigger value between a and b. Then returns smaller one between the value and c.
	//c - default value : 100
	auto big = [&](const int& a, const int& b, const int& c = 100)->int {
		return (a > b ? a : b) > c ? c : (a > b ? a : b);
	};
	
	int x = big(3, 5);//Excuted with default value 100
	int y = big(100, 60);//Excuted with default value 100
	int z = big(30, 60, 50);//All arguments are set 
	//Prints values returned
	cout << x << " " << y << " " << z << endl;
}
