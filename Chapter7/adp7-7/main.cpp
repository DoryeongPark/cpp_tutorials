#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Template : BaseMemory
template<typename T>
class BaseMemory {
	vector<T> mem;//Memory expressed by vector
protected:
	//Constructor - Initiates memory size
	BaseMemory(const int& size) { mem.resize(size); }
	//Memory Getter
	vector<T>& get_memory(){
		return mem;
	}
};
//Template : ROM inherits BaseMemory class
template<typename T>
class ROM : BaseMemory<T>{
public:
	//Constructor - Calls BaseMemory's constructor and copies memory from another vector
	ROM(const int& size, vector<T>& vec) : BaseMemory<T>(size){
		auto i = 0;
		//Copies memory from vector
		for (auto& a : vec)
			get_memory()[i++] = a;
	}
	//Returns value from memory location n
	T read(const int& n) {
		return get_memory()[n];
	}
};
//Template : RAM inhreits BaseMemory class
template<typename T>
class RAM : BaseMemory<T> {
public:
	//Constructor - Calls BaseMemory's constructor
	RAM(const int& size) : BaseMemory<T>(size) {}
	//Writes value in memory location index
	void write(const int& index, const T& val) {
		get_memory()[index] = val;
	}
	//Returns value from memory location index
	T read(const int& index) {
		return get_memory()[index];
	}
};

int main() {

	/* ---------- Case for type char ---------- */

	//vector for type char
	vector<char> x = { 'h', 'e', 'l', 'l', 'o' };

	//ROM and RAM instances for type char 
	ROM<char> biosROM{ 1024 * 10, x };
	RAM<char> mainMemory{ 1024 * 1024 };

	//Copies 5 values from ROM
	for (int i = 0; i < 5; ++i)
		mainMemory.write(i, biosROM.read(i));

	//Prints 5 values from RAM
	for (int i = 0; i < 5; ++i) 
		cout << mainMemory.read(i) << " ";
	
	cout << endl << endl;

	/* ---------- Case for type double ---------- */

	//vector for type double
	vector<double> y = { 10.5, 20.3, 30.11, 15.32 };

	//ROM and RAM instances for type char 
	ROM<double> dBiosROM{ 128, y };
	RAM<double> dMainMemory{ 128 * 128 };
	
	//Copies 5 values from ROM
	for (int i = 0; i < 4; ++i)
		dMainMemory.write(i, dBiosROM.read(i));

	//Prints 5 values from RAM
	for (int i = 0; i < 4; ++i)
		cout << dMainMemory.read(i) << " ";

	cout << endl << endl;

	/* ---------- Case for type string ---------- */

	//vector for type string
	vector<string> z = { "Hi,", "My name", "is", "Park Doryeong" };

	//ROM and RAM instances for type char 
	ROM<string> sBiosROM{ 128, z };
	RAM<string> sMainMemory{ 128 * 128 };

	//Copies 5 values from ROM
	for (int i = 0; i < 4; ++i)
		sMainMemory.write(i, sBiosROM.read(i));

	//Prints 5 values from RAM
	for (int i = 0; i < 4; ++i)
		cout << sMainMemory.read(i) << " ";

	cout << endl << endl;
	
}