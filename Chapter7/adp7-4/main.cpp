#include <iostream>	
#include <windows.h>
#include <string>	
#include <random>
#include <future>
#include <thread>

using namespace std;

class Point {
	int x; //Coordinate x 
	int y; //Coordinate y
public:
	//Constructor Setter : (Default Point - [0, 0], Default Color - White)
	Point(const int& _x = 0, const int& _y = 0) noexcept : x{ _x }, y{ _y } {
		setcolor(15, 15);
	};
	//Coordinate x Getter
	auto get_x() noexcept {
		return x;
	}
	//Coordinate y Getter
	auto get_y() noexcept {
		return y;
	}
	//Makes current point black than sets new coordinates
	void set_point(const int& _x, const int& _y) {
		setcolor(0, 0);//Black
		drawpoint(x, y);
		//Sets new coordinates
		x = _x;
		y = _y;
	}
	//Draws point on console screen
	void show() {
		setcolor(15, 15);
		drawpoint(x, y);
	}

protected:
	//Moves cursor on console screen
	void gotoxy(const int& x, const int& y) 
	{
		COORD Pos = { x - 1, y - 1 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	//Sets color with hex value 
	void setcolor(int color, int bgcolor)  
	{
		color &= 0xf;
		bgcolor &= 0xf;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
	}
	//Draws point(Point is regarded as one rectangle)
	void drawpoint(const int& x, const int& y) { 
		gotoxy(x * 2 + 1, y);
		cout << "  ";
		gotoxy(1, 1);
		setcolor(7, 0);
	}
};

//Point which has color - inherits Point class 
class ColorPoint : public Point {
	string color;//Color expressed with string
public:
	//Default constructor calls default constructor of Point(color : white)
	explicit ColorPoint() noexcept : Point{} {}
	//Calls Point class constructor and sets color
	ColorPoint(const int& x, const int& y, const string& _color) : Point{ x, y } {
		color = _color;
		update_color();//changes color as string
	}
	//Changes Point's color
	void set_color(const string& _color) {
		color = _color;
		update_color();
	}
	//Shows ColorPoint
	void show() {
		drawpoint(get_x(), get_y());
	}

private:
	//Determines color with member string variable
	void update_color() {
		if (color == "RED")
			setcolor(12, 12);//Red
		else if (color == "GREEN")
			setcolor(2, 2);//Green
		else if (color == "BLUE")
			setcolor(9, 9);//Blue
		else
			setcolor(15, 15);//Default Color : White
	}

};

int main() {

	ColorPoint zeroPoint;//Creates ZeroPoint(Default Point - White Point at [0, 0])
	zeroPoint.show();

	//Function - Creates 10 Random Color points at Random coordinate([1, 1] ~ [20, 20]) at every 2 seconds
	auto RandomPointGenerator = []() {
		auto counter = 0;//Number of points
		while (true) {

			random_device rd;
			mt19937 gen{ rd() };
			uniform_int_distribution<int> dist1(1, 20);//Random x coordinate
			decltype(dist1) dist2(1, 20);//Random y coordinate
			decltype(dist1) dist3(0, 2);//Random color [ 0 : red, 1 : green, 2 : blue ]

			switch (dist3(gen)) {
			case 0:
				ColorPoint{ dist1(gen), dist2(gen), "RED" }.show();
				break;
			case 1:
				ColorPoint{ dist1(gen), dist2(gen), "GREEN" }.show();
				break;
			case 2:
				ColorPoint{ dist1(gen), dist2(gen), "BLUE" }.show();
				break;
			}
			
			if (++counter == 10)
				return;

			this_thread::sleep_for(2s);//Sleep for 2 seconds
		}
	};

	auto fut = async(RandomPointGenerator);//Creates thread
	fut.get();//Run Thread

	getchar();

}