#include <iostream>	
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//Circle with radius
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
	void set_radius(const double& _radius) noexcept {
		radius = _radius;
	}
	//Calculates area
	auto getArea() noexcept {
		return 3.14 * radius * radius;
	}
};

//class NamedCircle inherited Circle class
class NamedCircle : public Circle {
	string name;
public:
	//Calls circle's constructor and sets name
	NamedCircle(const double& radius, const string& _name)
		noexcept : Circle{ radius }, name{ _name } {}
	//Shows circle's name and radius
	void show() noexcept {
		cout << "Circle name : " << name << endl;
		cout << "Radius : " << get_radius() << endl;
	}
	//name Getter
	auto get_name() noexcept {
		return name;
	}
};
//class CircleManager manages Circle instances
class CircleManager {
	vector<Circle*> storage;//Storage for Circle instances
public:
	//As soon as constructing CircleManager class, puts Circle instances inside.
	CircleManager() noexcept {

		string limit;//num of circles(string)
		int count;//number of circles(converted from limit)
		string input;//attributes of circles

		//Exception handling of input
		while (true) {
			try {
				cout << "몇 개의 원을 생성하시겠습니까? >> ";
				getline(cin, limit);//Gets limit
				count = abs(stoi(limit));//Converts limit into count(number)
				break;
			}
			catch (exception e) {//If limit isn't number
				cout << "올바른 입력 값을 입력해 주십시오." << endl;
			}
		}
		//Executes as count 
		for (int i = 0; i < count; ++i) {
			cout << i + 1 << ">> ";
			getline(cin, input);//Determines circle's attributes

			stringstream sin{ input };
			vector<string> tokens;//Storage for string tokens 

			while (sin) {
				getline(sin, input, ' ');//Gets one string token
				tokens.emplace_back(input);//Store it in storage
			}

			tokens.pop_back();//Pops back last one

			//Exception handling of input
			while (true) {
				try {
					if (tokens.size() < 2)//If number of tokens are not enough...
						throw exception{};//Throws exception
					//Generates NamedCircle instance which attributes are converted first token and second token
					storage.emplace_back(new NamedCircle{ stod(tokens[0]), tokens[1] });//Stores NamedCircle 
					break;
				}
				catch (const exception& e) {
					cout << "올바른 입력 값 또는 입력의 수를 입력해 주십시오." << endl;
					--i;//Repeats again
					break;
				}
			}

		}
	}
	//Prints Circle which area is the biggest
	auto get_biggest() noexcept {

		double max = 0;//Variable for biggest area
		string max_name = "";//Variable for Circle's name which has biggest area

		for_each(storage.begin(), storage.end(), [&](Circle* c) {
			//Downcasting Circle
			NamedCircle* nc = static_cast<NamedCircle*>(c);
			//If Circle's area is bigger than max...
			if (nc->getArea() > max) {
				max = nc->getArea();//Sets max as the circle's area
				max_name = nc->get_name();//Sets name as the circle's name
			}

		});
		//Prints max and max_name
		cout << "가장 면적이 큰 피자는 " << max_name << "이며 " <<
			"면적은 " << max << "입니다." << endl;
	}
	//Destructor
	~CircleManager() {
		for (auto& p : storage)//Releases all components
			delete p;
	}
};

int main() {
	CircleManager cm;//Input all Circles

	cm.get_biggest();//Prints the biggest circle
}