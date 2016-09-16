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
//Class Queue inherits class BaseArray
class MyQueue : public BaseArray {
	int tail = -1;//Indicates tail index of memory
public:
	//Calls BaseArray's constructor with parameter size
	MyQueue(const int& n) : BaseArray(n) {};
	//Inserts value in tail of memory
	void enqueue(const int& n) {
		put(++tail, n);
	}
	//Deletes value in front of memory and returns value deleted
	auto dequeue() {
		auto popped = get(0);
		//Moves 1 time left all components remained
		for (int i = 1; i <= tail; ++i)
			put(i - 1, get(i));
		//Decreases tail
		--tail;
		return popped;//return popped value
	}
	//Returns memory's length
	auto length() {
		return tail + 1;
	}
	//Returns memory's size
	auto capacity() {
		return get_capacity();
	}
};

int main() {

	MyQueue mQ{ 100 };//Creates MyQueue instance which size is 100
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶� >> ";
	//Input integer values to insert
	for (int i = 0; i < 5; ++i) {
		cin >> n;
		mQ.enqueue(n);//Inserts a value in MyQueue
	}
	//Prints queue's information
	cout << "ť�� �뷮 : " << mQ.capacity() << " ,ť�� ũ�� : " << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ� >> ";

	//Pops values from queue while they exist
	while (mQ.length()) 
		cout << mQ.dequeue() << " ";
	
	//Prints queue's length
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}