#include <iostream>
#include <vector>	

using namespace std;

int main() {
	//Functor add
	struct add {
		add():sum(0), i(0){}//Set member initial values
		
		//function1 : returns number added by all numbers of vector
		int operator()(vector<int>& v, const int& num) noexcept{
			for (auto a : v) 
				if(i++ < num)//limit : num
					sum += a; //accumlates numbers from vector
			return sum;
		}
		//function2 : returns number added by all numbers of 2 vectors
		int operator()(vector<int>& v1, const int& num, vector<int>& v2) noexcept{
			while (i < num) {//limit : num
				sum += (v1[i] + v2[i]); ++i;//accumulates numbers from two vectors
			}
			return sum;
		};

	private:
		int sum; //number accumulated
		int i; //loop variable
	};
	
	vector<int> a = { 1, 2, 3, 4, 5 };//Initializes vector a
	vector<int> b = { 6, 7, 8, 9, 10 };//Initializes vector b
	
	int c = add{}(a, 5);//get added number by 5 numbers of vector a
	int d = add{}(a, 5, b);//get added number by 5 numbers of each vectors(a, b)

	cout << c << endl;
	cout << d << endl;
}