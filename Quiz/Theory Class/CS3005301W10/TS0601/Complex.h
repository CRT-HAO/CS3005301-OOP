// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 25, 2023
// Last Update: April 25, 2023
// Problem statement: Complex

#pragma once

#include <iostream>
#include <string>

#include <stdio.h>

using namespace std;

class Complex
{
public:
	double realValue, imaginaryValue;

	Complex() : realValue(0), imaginaryValue(0) { };

	Complex(double r) : realValue(r), imaginaryValue(0) { };

	Complex(double r, double i) : realValue(r), imaginaryValue(i) { };

	double real() { return this->realValue; };

	double imag() { return this->imaginaryValue; };

	double norm()
	{ return sqrt(pow(this->realValue, 2) + pow(this->imaginaryValue, 2)); }

	friend double real(Complex c) { return c.real(); };

	friend double imag(Complex c) { return c.imag(); };

	friend double norm(Complex c) { return c.norm(); };

	Complex operator+(Complex c)
	{
		Complex r = (*this);
		r.realValue += c.realValue;
		r.imaginaryValue += c.imaginaryValue;
		return r;
	}

	Complex operator-(Complex c)
	{
		Complex r = (*this);
		r.realValue -= c.realValue;
		r.imaginaryValue -= c.imaginaryValue;
		return r;
	}

	Complex operator*(Complex c)
	{
		// (a+bi)(c+di) = (ac-bd) + (bc+ad)i
		Complex r;
		r.realValue = ((this->realValue * c.realValue) -
			(this->imaginaryValue * c.imaginaryValue));
		r.imaginaryValue = ((this->imaginaryValue * c.realValue) +
			(this->realValue * c.imaginaryValue));
		return r;
	}

	Complex operator/(Complex c)
	{
		// (a+bi)/(c+di) = (ac+bd)/(c^2+d^2) + ((bc-ad)/(c^2+d^2))i
		Complex r;
		r.realValue = (
			(
				(this->realValue * c.realValue)
				+
				(this->imaginaryValue * c.imaginaryValue)
			)
			/
			(pow(c.realValue, 2) + pow(c.imaginaryValue, 2))
			);
		r.imaginaryValue = (
			(
				(this->imaginaryValue * c.realValue)
				-
				(this->realValue * c.imaginaryValue)
			)
			/
			(pow(c.realValue, 2) + pow(c.imaginaryValue, 2))
			);
		return r;
	}

	friend Complex operator+(double d, Complex c)
	{ return (Complex(d) + c); }

	friend Complex operator-(double d, Complex c)
	{ return (Complex(d) - c); }

	friend Complex operator*(double d, Complex c)
	{ return (Complex(d) * c); }

	friend Complex operator/(double d, Complex c)
	{ return (Complex(d) / c); }

	friend bool operator==(Complex c1, Complex c2)
	{
		return (
			(c1.realValue == c2.realValue)
			&&
			(c1.imaginaryValue == c2.imaginaryValue)
			);
	}

	friend ostream& operator<<(ostream& strm, const Complex& c)
	{
		strm << c.realValue << " + " << c.imaginaryValue << "*i";
		return strm;
	}

	friend istream& operator>>(istream &strm,Complex &c)
	{
		string s;
		getline(strm, s);
		sscanf_s(s.c_str(), "%*c = %lf + %lf*i",
			&(c.realValue), &(c.imaginaryValue));
		return strm;
	}
};