#include <iostream>

using namespace std;
//Class circle
class Circle {
	int radius;//Circle radius
public:
	//Setter constructor
	Circle(const int& _radius = 0) {
		radius = _radius;
	}
	//Prints radius
	void show() {
		cout << "radius = " << radius << "ÀÎ ¿ø" << endl;
	}
	//Declares friend operator function
	friend Circle& operator+ (const int& x, Circle& c);
};
//Operator function : returns Circle which radius's increased by x 
Circle& operator+ (const int& x, Circle& c) {
	return Circle(c.radius + x);
}

int main() {
	Circle a{ 5 }, b{ 4 };//Instantiate Circles
	b = 1 + a;//Copies Circle with radius(a's radius + 1)
	a.show();
	b.show();
}