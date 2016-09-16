#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <iterator>

using namespace std;
//Class Matrix
class Matrix {
	deque<int> mat;//2*2 Integer Matrix
public:
	Matrix() = default;
	//Setter constructor
	Matrix(const int& a1, const int& a2,
		const int& a3, const int& a4) {
		//Push arguments
		mat.emplace_back(a1);
		mat.emplace_back(a2);
		mat.emplace_back(a3);
		mat.emplace_back(a4);
	}
	//Prints Matrix components
	void show() {
		cout << "Matrix = { ";

		for (auto a : mat)
			cout << a << " ";

		cout << "}" << endl;
	}
	//Declares friend operator functions
	friend Matrix& operator>> (Matrix& mat, vector<int>& v1);
	friend Matrix& operator<< (Matrix& mat, vector<int>& v1);
	friend Matrix& operator> (Matrix& m, const int& a);
	friend Matrix& operator< (Matrix& m, const int& a);
};
//Operator Function : Copies matrix components to integer array
Matrix& operator>> (Matrix& mat, vector<int>& v1) {
	for (auto a : mat.mat)
		v1.emplace_back(a);
	return mat;
}
//Operator Function : Copies integer array components to Matrix
Matrix& operator<< (Matrix& mat, vector<int>& v1) {
	copy(v1.begin(), v1.end(), back_inserter(mat.mat));
	return mat;
}
//Operator Function : Moves Matrix components 'a' times on clockwise
Matrix& operator> (Matrix& m, const int& a) {
	for (int i = 0; i < a; ++i) {
		int shifted = m.mat.back();//Gets component from back
		m.mat.pop_back();//Remove back component
		m.mat.emplace_front(shifted);//Inserts component in front of Matrix
	}
	return m;
}
//Operator Function : Moves Matrix components 'a' times on anticlockwise
Matrix& operator< (Matrix& m, const int& a) {
	for (int i = 0; i < a; ++i) {
		int shifted = m.mat.front();//Gets component from front
		m.mat.pop_front();//Removes front component 
		m.mat.emplace_back(shifted);//Inserts component back of Matrix 
	}
	return m;
}
int main() {

	Matrix a{ 4,3,2,1 }, b;//2*2 Matrix a, Empty Matrix b

	vector<int> x; //Empty Integer array x
	vector<int> y = { 1,2,3,4 };//Integer array y

	a >> x;//Copies Matrix a to array x
	b << y;//copies array y to Matrix b

	for (int i = 0; i < 4; ++i)//Prints array x
		cout << x[i] << " ";

	cout << endl;
	b.show();//Prints Matrix b

	cout << "b > 1" << endl;
	b > 1;//Move Matrix b's components 1 time on clockwise
	b.show();//Prints matrix b

	cout << "b < 2" << endl;
	b < 2;//Move Matrix b's components 2times on anticlockwise
	b.show();//Prints matrix b
}