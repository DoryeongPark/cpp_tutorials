#include <iostream>
#include <memory>	
#include <string>

using namespace std;
//Class BaseArray expresses base memory
class BaseArray {
	int capacity; //Memory size
	unique_ptr<int> mem; //unique pointer(No need to release with destructor)
protected:
	//Setter constructor : sets memory size and allocates memory
	BaseArray(const int& _capacity = 100) {
		capacity = _capacity;
		mem.reset(new int[capacity]);
	}
	//Puts value on index memory location
	void put(const int& index, const int& val) {
		index[mem.get()] = val;
	}
	//Gets value from index memory location
	auto get(const int& index) {
		return mem.get()[index];
	}
	//Memory size getter
	auto get_capacity() {
		return capacity;
	}
};
//Class MyStack inherits BaseArray
class MyStack : BaseArray {
	int top = -1; //Top index
public:
	//Calls BaseArray's constructor with parameter n(size)
	MyStack(const int& n) : BaseArray(n) {}
	//Pushes value n into memory
	void push(const int& n) {
		put(++top, n);
	}
	//Pops and Returns value from memory
	auto pop() {
		return get(top--);
	}
	//Gets memory's length
	auto length() {
		return top + 1;
	}
	//Gets memory's size
	auto capacity() {
		return get_capacity();
	}
};

int main() {
	//Creates MyStack instance which has size 100
	MyStack mStack{ 100 };
	int n; 

	cout << "스택에 삽입할 5개의 정수를 입력하라 >> ";
	//Input values in MyStack
	for (int i = 0; i < 5; ++i) {
		cin >> n;
		mStack.push(n);//Pushes Input value into MyStack
	}
	//Prints MyStack's information
	cout << "스택의 용량 : " << mStack.capacity() << ", 스택의 크기 : " << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다 >> ";
	//Pops values up from back of memory and prints them
	while (mStack.length()) 
		cout << mStack.pop() << " ";
	
	//Prints myStack's length
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}