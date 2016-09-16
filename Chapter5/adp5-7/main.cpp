#include <iostream>
#include <random>
#include <ctime>

using namespace std;
//Function 1 : Sets seed
auto f1 = []() {
	srand((unsigned int)time(NULL));
};
//Function 2 : Returns one random integer between min and max
auto f2 = [](const int& min = 0, const int& max = 32767)->int {
	random_device rd;//Random device
	mt19937 generator{ rd() };//Mersenne Twister random number generator
	uniform_int_distribution<int> dist(min, max);//Distributor(Range)
	return dist(generator);
};
//Function 3 : Returns Random alphabet
auto f3 = []()->char {
	random_device rd1, rd2;//Random device
	mt19937 generator1{ rd1() };//Mersenne Twister random number generator
	mt19937 generator2{ rd2() };
	uniform_int_distribution<int> dist(97, 122);//ASCII value(a ~ z)
	uniform_int_distribution<int> to_upper(0, 1);//Lowercase(0) or Uppercase(1)
	
	if (to_upper(generator2))//If it is determined as uppercase
		return toupper(dist(generator1));//Returns Uppercase
	else //If it is determined as lowercase
		return dist(generator1);//Resturs Lowercase
};
//Function 4 : Returns random real number between 0 and 1
auto f4 = []()->double {
	random_device rd;//Random device
	mt19937 generator{ rd() };//Mersenne Twister random number generator
	uniform_real_distribution<double> dist(0.0, 1.0);//Real number Distributor

	return dist(generator);//Returns Random real number
};

class Random {
public://static member functions
	static decltype(f1) seed;
	static decltype(f2) nextInt;
	static decltype(f3) nextAlphabet;
	static decltype(f4) nextDouble;
};
//Initializes static member functions
decltype(f1) Random::seed = f1;
decltype(f2) Random::nextInt = f2;
decltype(f3) Random::nextAlphabet = f3;
decltype(f4) Random::nextDouble = f4;

int main() {
	Random::seed();//Sets seed

	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; ++i) //Prints 10 random numbers on 0 ~ 100
		cout << Random::nextInt(0, 100) << " ";
	
	cout << endl << endl;

	cout << "알파벳을 랜덤하게 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; ++i) //Prints 10 random alphbets
		cout << Random::nextAlphabet() << " ";

	cout << endl << endl;

	cout << "랜덤한 실수를 10개 출력합니다." << endl;
	for (int i = 0; i < 10; ++i)//Prints 10 random real numbers on 0 ~ 1
		cout << Random::nextDouble() << " ";

	cout << endl << endl;
}