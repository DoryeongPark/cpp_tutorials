#include "Circle.h"

using namespace std;

int Circle::circle_num = 1;

Circle::Circle(const double& r){

	num = circle_num++;

	cout << "�� " << num << "�� ������ >> ";

	string input;

	try {
		getline(cin, input, '\n');
		
		for (auto c : input) {
			if (!(isdigit(c) || c == '.'))
				throw input;
		}
	}
	catch (...) {
		cout << " ���ڰ� �ƴմϴ�." << endl;
		exit(0);
	}
	
	radius = stod(input);
	area = M_PI * M_PI * radius;
}

Circle::~Circle() noexcept{
	circle_num--;
}

double Circle::getArea() noexcept{
	return area;
}

int Circle::getCircleNum() noexcept{
	return num;
}

