// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: February 23, 2023
// Last Update: February 24, 2023
// Problem statement: Compute the square root

#include <iostream>

using namespace std;

// Intent: Compute the square root
// Pre: The variable n is a floating-point number
// Post: The function return the square root of n
double squareRoot(double n)
{
	double guess = n / 2;
	double r = 0;
	double lastR = r;
	for (;;)
	{
		r = n / guess;
		guess = (guess + r) / 2;
		if ((r - lastR) < 0.01)
			break;
		lastR = r;
	}
	return r;
}

int main()
{
	for (;;)
	{
		double n = 0, r = 0;

		// get the number from istream
		cin >> n;

		// if get a EOF from istream
		if (cin.eof())
			break;

		// compute the square root of n use squareRoot() function
		r = squareRoot(n);

		// output the answer,
		// and make the number to two decimal
		cout.precision(2);
		cout << fixed << r << endl;
	}

	return 0;
}