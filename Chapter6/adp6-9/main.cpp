#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Statistics {
	vector<int> data;//Integer Stack
public:
	Statistics() = default;
	//Push data
	Statistics& operator<<(const int& a) {
		data.emplace_back(a);
		return *this;
	}
	//Determines stack's empty or not
	bool operator! () {
		if (data.empty())
			return true;
		else
			return false;
	}
	//Prints data
	void operator~ () {
		for (auto& a : data)
			cout << a << " ";

		cout << endl;
	}
	//Puts average on reference parameter
	void operator>> (int& avg) {
		//If data's empty, prints string and exit
		if (!*this) {
			cout << "�����Ͱ� �������� �����Ƿ� ����� ���� �� �����ϴ�." << endl;
			return;
		}
		//Accumulator variable
		int sum = 0;
		//Accumulate data
		for (auto& a : data)
			sum += a;
		//get average
		avg = sum / data.size();
	}
	//Sorts data with ascending order
	void operator&() {
		sort(data.begin(), data.end());
	}
	//Deletes all of data
	void operator*() {
		data.clear();
	}
	//Add 2 Statistics data
	Statistics& operator+(Statistics& st) {
		for_each(st.data.begin(), st.data.end(), [&](int a) {
			data.emplace_back(a);
		});
		return *this;
	}
};
int main() {
	Statistics stat1;//Data Array1

	if (!stat1)//If it is empty...
		cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

	int x[5];//Input Array

	cout << "5���� ������ �Է��϶� >> ";

	for (int i = 0; i < 5; ++i)//Input data
		cin >> x[i];

	for (int i = 0; i < 5; ++i)//Input all data in Data Array1
		stat1 << x[i];

	stat1 << 100 << 200;//Insert two data in Data Array1
	~stat1;//Prints all data 

	int avg;//Variable to get average
	stat1 >> avg;//Get average of Data Array1
	cout << "avg = " << avg << endl;//Prints average

	cout << "�����͸� �����մϴ�." << endl;
	&stat1;//Sorts Data Array1 
	
	~stat1;//Prints Data Array1 

	Statistics stat2;//Data Array2

	cout << "3���� ������ �Է��϶� >> "; 

	int y[3];//Input Array
	
	for (int i = 0; i < 3; ++i)//Input data
		cin >> y[i];

	for (int i = 0; i < 3; ++i)//Input all Data in Data Array2
		stat2 << y[i];

	cout << "�����͸� ��Ĩ�ϴ�.";

	stat2 = stat1 + stat2;//Merge two Data Array

	~stat2;//Print data
	
	cout << "�����͸� ��� �����մϴ�." << endl;
	
	*stat2;//Remove all of data

	if (!stat2)
		cout << "���� ��� �����Ͱ� �����ϴ�." << endl;
}