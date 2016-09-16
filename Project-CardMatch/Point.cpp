#include "Point.h"
#include "common.h"
Point::Point() {}

//x, y를 매개변수로 받아서 바로 초기화하는 생성자
Point::Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}

//x의 값을 반환해줌
int Point::getX()
{
	return x;
}
//y의 값을 반환해줌
int Point::getY()
{
	return y;
}

//Point클래스의 인스턴트를 바로 출력할 수 있도록 오버라이딩
ostream& operator << (ostream& os, const Point& p)
{
	os << "[" << p.x << "," << p.y << "]";
	return os;
}

//대입을 편하게 하기위해 =연산자 오버라이딩
Point& Point::operator = (const Point &p)
{
	x = p.x;
	y = p.y;
	return *this;
}

//비교를 편하게 하기위해 ==연산자 오버라이딩
bool Point::operator == (const Point &p)
{
	return (x == p.x) && (y == p.y);
}

//비교를 편하게 하기위해 !=연산자 오버라이딩
bool Point::operator != (const Point &p)
{
	return !((x == p.x) && (y == p.y));
}

bool Point::checkBoardRange()
{
	//보드 범위 이내의 좌표가 입력되었는지 확인하여
	//범위 밖일 경우 false, 범위 내일 경우 true 리턴
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
		return false;
	return true;
}