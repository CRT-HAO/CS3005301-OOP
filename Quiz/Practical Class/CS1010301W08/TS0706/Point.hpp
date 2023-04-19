// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 19, 2023
// Last Update: April 19, 2023
// Problem statement: Shisensho

#pragma once

#include <iostream>

class Point
{
public:
	int _x;
	int _y;

	Point(int x = 0, int y = 0) : _x(x), _y(y) { };

	inline bool inRange(int size) const
	{
		if (this->_x < 0 || this->_x >= size)
			return false;
		if (this->_y < 0 || this->_y >= size)
			return false;

		return true;
	}

	inline Point operator=(const Point& point)
	{ return Point(point._x, point._y); }

	inline friend std::istream& operator>>(std::istream& is, Point& point)
	{
		is >> point._x >> point._y;
		point._x++;
		point._y++;
		return is;
	}

	inline friend bool operator==(const Point& p1, const Point& p2)
	{
		if (p1._x == p2._x && p1._y == p2._y)
			return true;

		return false;
	}

	inline friend Point operator+(const Point& p1, const Point& p2)
	{ return Point(p1._x + p2._x, p1._y + p2._y); }

};