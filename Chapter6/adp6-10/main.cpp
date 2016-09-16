#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Stack {
	vector<int> arr;//Stack Integer data
public:
	//Determines stack is empty or not
	auto operator!() {
		if (arr.empty())
			return true;
		else
			return false;
	}
	//Push data in stack
	Stack& operator<< (const int& a) {
		arr.emplace_back(a);
		return *this;
	}
	//Pop data in stack(Returns popped value with referance parameter)
	void operator>> (int& a) {
		a = arr.back();
		arr.pop_back();
	}

	//Removes all Stack components
	Stack& operator--() {
		arr.clear();
		return *this;
	}
	//Sorts all of Stack components with ascending order
	void operator&() {
		sort(arr.begin(), arr.end());
	}
	//Prints all of Stack components
	void operator~() {
		for_each(arr.begin(), arr.end(), [&](int a) {
			cout << a << " ";
		});
		cout << endl;
	}
};

int main() {

	Stack stack;//Integer stack

	stack << 3 << 5 << 10;//Push data

	while (true) {
		if (!stack)//If Stack's empty, break loop
			break;

		auto x = 0;
		stack >> x;//Pop back value and store
		cout << x << " ";//Print popped value
	}

	cout << endl;

	stack << 3 << 5 << 10 << 8 << 4;//Push Data in stack
	
	&stack;//Sorts all of data

	cout << "스택이 정렬 되었습니다." << endl;
	
	~stack;//Prints all of data

	cout << "스택 내의 모든 값을 지웁니다." << endl;

	--stack;//Removes all of data in stack

	if (!stack)//Prints string if stack's empty
		cout << "스택이 비었습니다." << endl;
	
}