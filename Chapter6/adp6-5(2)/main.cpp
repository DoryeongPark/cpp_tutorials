#include <iostream>	
#include <deque>
#include <algorithm>

using namespace std;

//Class Matrix
class Matrix {
	deque<int> mat;//2*2 Integer Matrix
public:
	Matrix() = default;
	//Setter constructor
	Matrix(const int& a1, const int& a2,
		const int& a3, const int& a4) {
		//Pushes integer in Matrix
		mat.emplace_back(a1);
		mat.emplace_back(a2);
		mat.emplace_back(a3);
		mat.emplace_back(a4);
	}
	//Prints Matrix components
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; ++i)
			cout << mat[i] << " ";
		cout << "}" << endl;
	}
	//Declares friend Operator functions
	friend Matrix operator+ (const Matrix& m1, const Matrix& m2);
	friend Matrix& operator+= (Matrix& m1, const Matrix& m2);
	friend Matrix operator* (const Matrix& m1, const Matrix& m2);
	friend Matrix& operator*= (Matrix& m1, const Matrix m2);
	friend auto operator == (const Matrix& m1, const Matrix& m2);

};
//Operator Function :  Adds two Matricies and return it
Matrix operator+ (const Matrix& m1, const Matrix& m2) {
	return Matrix(m1.mat[0] + m2.mat[0], m1.mat[1] + m2.mat[1],
		m1.mat[2] + m2.mat[2], m1.mat[3] + m2.mat[3]);
}
//Operator Function :  Increases Matrix by another Matrix
Matrix& operator+= (Matrix& m1, const Matrix& m2) {
	m1.mat[0] += m2.mat[0];
	m1.mat[1] += m2.mat[1];
	m1.mat[2] += m2.mat[2];
	m1.mat[3] += m2.mat[3];
	return m1;
}
//Operator Function :  Multiplies two Mitricies and return it
Matrix operator* (const Matrix& m1, const Matrix& m2) {
	return Matrix(m1.mat[0] * m2.mat[0] + m1.mat[1] * m2.mat[2],
		m1.mat[0] * m2.mat[1] + m1.mat[1] * m2.mat[3],
		m1.mat[2] * m2.mat[0] + m1.mat[3] * m2.mat[2],
		m1.mat[2] * m2.mat[1] + m1.mat[3] * m2.mat[3]);
}
//Operator Function : Multiplies Matrix by another Matrix
Matrix& operator*= (Matrix& m1, const Matrix m2) {
	deque<int> temp = m1.mat;
	m1.mat[0] = temp[0] * m2.mat[0] + temp[1] * m2.mat[2];
	m1.mat[1] = temp[0] * m2.mat[1] + temp[1] * m2.mat[3];
	m1.mat[2] = temp[2] * m2.mat[0] + temp[3] * m2.mat[2];
	m1.mat[3] = temp[2] * m2.mat[1] + temp[3] * m2.mat[3];
	return m1;
}
//Determines two Matrices are same or not
auto operator == (const Matrix& m1, const Matrix& m2) {
	if (m1.mat[0] == m2.mat[0] && m1.mat[1] == m2.mat[1] &&
		m1.mat[2] == m2.mat[2] && m1.mat[3] == m2.mat[3])
		return true;
	else
		return false;
}

int main() {
	Matrix a{ 1,2,3,4 };//Matrix 1, 2, 3, 4
	Matrix b{ 2,3,4,5 };//Matrix 2, 3, 4, 5
	Matrix c;//Empty Matrix

	c = a + b;//Add Matrix a, b and stores it in c
	a += b;//Increase Matrix a by Matrix b
	a.show(); b.show(); c.show();//Prints Matrix a, b, c

	if (a == c)//If a and c are same
		cout << "a and c are same." << endl;

	Matrix d;//Empty Matrix d

	a *= c;//Multiplies a by c
	cout << "result of a * c" << endl;
	a.show();//Prints a
	cout << "result of b * c" << endl;
	d = b * c;//Multiplies b and c and stores it in d
	d.show();//Prints d
}