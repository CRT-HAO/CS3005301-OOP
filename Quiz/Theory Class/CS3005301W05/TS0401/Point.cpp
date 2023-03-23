// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 23, 2023
// Last Update: March 23, 2023
// Problem statement: Fraction

#include "Point.h"

void Point::Set(int vertical, int horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

void Point::Move(int x, int y)
{
	this->vertical += x;
	this->horizontal += y;
}

void Point::Rotate()
{
	swap(this->vertical, this->horizontal);
	this->horizontal *= -1;
}
