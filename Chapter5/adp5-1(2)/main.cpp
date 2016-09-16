#include <iostream>
#include <vector>	

using namespace std;

int main() {
	//Functor add
	struct add {
		add() :sum(0), i(0) {}//Initializes member variables

		//function 1 : Returns number added by numbers from vector1, vector2(default)
		int operator()(vector<int>& v1, const int& num, vector<int>& v2 = vector<int>()) noexcept {
			if (v2.empty())//If vector2 is default argument...
				for (int i = 0; i < num; ++i)
					v2.push_back(0);//Initializes all components with 0

			while (i < num) {//limit : num
				sum += (v1[i] + v2[i]); ++i;//accumulates numbers from vector1, vector2 on varible sum
			}
			return sum;
		};

	private:
		int sum;//number accumulated
		int i;//loop variable
	};

	vector<int> a = { 1, 2, 3, 4, 5 };//initializes vector a
	vector<int> b = { 6, 7, 8, 9, 10 };//initializes vector b

	int c = add()(a, 5);//add 5 numbers from vector a
	int d = add()(a, 5, b);//add each 5 numbers from vector a, b

	//print each numbers accumulated
	cout << c << endl;
	cout << d << endl;
}