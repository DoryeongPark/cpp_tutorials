#include <iostream>	
#include <string>	

using namespace std;

//class Circle
class Circle {
	double radius;
public:
	//Setter constructor
	Circle(const double& _radius = 0) noexcept {
		radius = _radius;
	}
	//radius Getter
	auto get_radius() {
		return radius;
	}
	//radius Setter
	void set_radius(const double& _radius) {
		radius = _radius;
	}
	//Calculates circle's area
	auto getArea() {
		return 3.14 * radius * radius;
	}
};

//NamedCircle class inherited Circle class
class NamedCircle : public Circle {
	string name;
public:
	//Calls direct class's constructor and set circle's name
	NamedCircle(const double& radius, const string& _name) : Circle(radius), name(_name) {}
	//Prints circle's members
	void show() {
		cout << "Circle name : " << name << endl;
		cout << "Radius : " << get_radius() << endl;
	}
};

int main() {
	//Instantiates Circle which has radius 3
	NamedCircle waffle{ 3, "waffle" };
	waffle.show();//Prints Circle's members
}