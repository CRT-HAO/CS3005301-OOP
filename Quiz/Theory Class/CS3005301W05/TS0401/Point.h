// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 23, 2023
// Last Update: March 23, 2023
// Problem statement: Fraction

#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point
{
private:
	int vertical;
	int horizontal;

public:
	Point()
	{
		vertical = 0;
		horizontal = 0;
	}

	// Intent: Reset the coordinate position
	//         of the point by the given the x and y.
	// Pre: The variable vertical is x value, horizontal is y value
	void Set(int vertical, int horizontal);

	// Intent: Move the current point x pixels
	//         on the x-axis and y pixels on the y-axis.
	// Pre: The variable x and y is move size
	void Move(int x, int y);

	// Intent: Rotate this point 90 degrees clockwise from the origin.
	void Rotate();

	// Intent: Get the value x of the point.
	// Post: The function returns value x
	int RetrieveVertical() const { return vertical; }

	// Intent: Get the value y of the point.
	// Post: The function returns value y
	int RetrieveHorizontal() const { return horizontal; }
};

#endif //Point_H