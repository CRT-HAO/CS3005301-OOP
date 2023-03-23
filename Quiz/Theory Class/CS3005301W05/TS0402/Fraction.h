// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 23, 2023
// Last Update: March 23, 2023
// Problem statement: Fraction

#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include <iomanip>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

	static int gcd(int a, int b);
public:
	Fraction();

	// Intent: Set fraction numerator
	// Pre: The variable nu is numerator
	void setNumerator(int nu);

	// Intent: Set fraction denominator
	// Pre: The variable nu is denominator
	void setDenominator(int de);

	// Intent: Print fraction in float-number
	void getDouble();

	// Intent: Print reduced fraction
	void outputReducedFraction();
};

#endif //Fraction_H