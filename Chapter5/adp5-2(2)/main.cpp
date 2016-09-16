#include <iostream>
#include <functional>
#include <string>

using namespace std;
/*
*	Person which has name, weight and id
*/
class Person {
	int id; 
	double weight;
	string name;
public:
	//Constructor 1(default value - id : 1, name : "Grace", weight : 20.5) : Sets member variables
	Person(const int& id = 1, const string& name = "Grace", const double& weight = 20.5) {
		this->id = id;
		this->weight = weight;
		this->name = name;
	}
	//Function for printing its member variables
	function<void()> show = [&]()->void {
		cout << id << " " << weight << " " << name << endl;
	};
};
int main() {
	Person grace;//Constructed with default values
	Person ashley{ 2, "Ashely" };//Constructed with 2 arguments, 1 default value
	Person helen{ 3, "Helen", 32.5 };//Constructed with 3 arguments
	//Prints member variables of each Objects
	grace.show();
	ashley.show();
	helen.show();
}