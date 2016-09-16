#include <iostream>

using namespace std;
//class Circle
class Circle {
	int radius;//Circle radius
public:
	//Setter constructor
	Circle(const int& _radius = 0) {
		radius = _radius;
	}
	//Prints Radius
	void show() {
		cout << "radius = " << radius << "ÀÎ ¿ø" << endl;
	}
	//Declares Operator functions
	friend Circle& operator++ (Circle& c);
	friend Circle& operator++ (Circle& c, int x);
};
//Prefix increase operator function
Circle& operator++ (Circle& c) {
	return Circle(++c.radius);//return increased Circle
}
//Postfix increase operator function
Circle& operator++ (Circle& c, int x) {
	return Circle(c.radius++);//return circle and increase
}

int main() {
	Circle a{ 5 }, b{ 4 };//Instatniate Circles
	++a;//Increase radius
	b = a++;//copy and Increase radius
	a.show();
	b.show();
}