#include <iostream>	
#include <windows.h>
#include <string>	

using namespace std;

class Point {
	int x; //Coordinate x 
	int y; //Coordinate y 
public:
	//Constructor Setter : (Default Point - [0, 0], Default Color - White)
	Point(const int& _x = 0, const int& _y = 0) noexcept : x{ _x }, y{ _y } {
		setcolor(15, 15);//White
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
	string color; //Color expressed with string
public:
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
	//Creates red point on [5, 5]
	ColorPoint cp1{ 5, 5, "RED" };
	cp1.set_point(10, 10);//Changes coordinate [10, 10]
	cp1.set_color("BLUE");//Changes color blue
	cp1.show();//Shows point on console screen

	ColorPoint cp2{ 10, 3, "GREEN" };//Creates green point on [10, 3]
	cp2.show();//Shows the point

	Point cp3{ 3, 9 };//Create default point(white) on [3, 9]
	cp3.show();//Shows the point

	getchar();//Pause
}