// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 23, 2023
// Last Update: March 23, 2023
// Problem statement: Fraction

#include "Fraction.h"

Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 0;
}

void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

void Fraction::getDouble()
{
	double f = (double)(this->numerator) / (double)(this->denominator);
	if (f != (int)f)
		std::cout << std::fixed << std::setprecision(6);
	else
		std::cout << std::setprecision(0);
	std::cout << f << std::endl;
}

void Fraction::outputReducedFraction()
{
	int g = Fraction::gcd(abs(this->numerator), abs(this->denominator));
	int nu = (this->numerator) / g;
	int de = (this->denominator) / g;
	if (nu == 0 || de == 0)
		std::cout << 0 << std::endl;
	else if (de == 1)
		std::cout << nu << std::endl;
	else
		std::cout << nu << '/' << de << std::endl;
}

int Fraction::gcd(int a, int b)
{
	return b == 0 ? a : Fraction::gcd(b, a % b);
}