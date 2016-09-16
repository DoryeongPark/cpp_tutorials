#include <iostream>
#include <functional>
#include <string>

using namespace std;

class Person {
	int id = 1;//default value : 1
	double weight = 20.5;//default value : 20.5
	string name = "Grace";//default value : "Grace"
public:
	Person() = default;
	//Constructor1 : set id & name
	Person(const int& id, const string& name) {
		this->id = id;
		this->name = name;
	}
	//Constructor2 : set id, name and weight
	Person(const int& id, const string& name, const double& weight) {
		this->id = id;
		this->weight = weight;
		this->name = name;
	}
	//function for print members
	function<void()> show = [&]()->void{
		cout << id << " " << weight << " " << name << endl;
	};
};
int main() {
	Person grace;//Person object constructed by default constructor
	Person ashley{ 2, "Ashely" };//Person object constructed by constructor1
	Person helen{ 3, "Helen", 32.5 };//Person object construced by constructor2
	
	//Prints components of each Person objects
	grace.show();
	ashley.show();
	helen.show();
}