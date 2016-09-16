#include <iostream>

using namespace std;

class MyVector {
	int* mem;//integer array
	int size;//array's size
public:
	//Constructor with 2 arguments(default array size - 100, array value - 0)
	MyVector(const int& n = 100, const int& val = 0) {
		mem = new int[n];
		size = n;
		for (int i = 0; i < size; ++i)
			mem[i] = val;
	}
	//Destructor : Release array memory
	~MyVector() { delete[] mem; }
	//Function for printing array components
	void show() noexcept{
		for (int i = 0; i < size; ++i)
			cout << i[mem] << " ";

		cout << endl;
		//Prints member variables
		cout << "Vector size : " << size << endl;
		cout << "Value : " << 0[mem] << endl << endl;//members all same
	}
};
int main() {
	MyVector vec1 = MyVector{};//Constructed by default values
	MyVector vec2 = MyVector{10};//Constructed by 1 argument, 1 default value
	MyVector vec3 = MyVector{10, 3};//Constructed by 2 arguments

	cout << "Vector 1" << endl;
	vec1.show();//Prints components of vector1

	cout << "Vector 2" << endl;
	vec2.show();//Prints components of vector2

	cout << "Vector 3" << endl;
	vec3.show();//Prints components of vector3
}