// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 24, 2023
// Last Update: April 24, 2023
// Problem statement: Design Polynomial Class

#include "Polynomial.h"

Polynomial::Polynomial()
{
	this->_c = {};
};

Polynomial::Polynomial(double* param, int size)
{
	this->_c = std::vector<double>(param, param + size);
}

Polynomial::Polynomial(const Polynomial& poly)
{
	this->_c = poly._c;
}

int Polynomial::mySize() const
{
	for (int i = this->_c.size() - 1; i >= 0; i--)
		if (this->_c[i] != 0)
			return (i + 1);

	return 0;
}

double& Polynomial::operator[](int index)
{
	while (index > this->_c.size() - 1)
		this->_c.push_back(0);
	return this->_c[index];
}

Polynomial& Polynomial::operator=(const Polynomial& poly)
{
	this->_c = poly._c;
	return (*this);
}

Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial r = poly1;

	size_t s = poly2._c.size();

	if (r._c.size() < s)
		r._c.resize(s, 0);

	for (size_t i = 0; i < s; i++)
		r._c[i] += poly2._c[i];

	return r;
}

Polynomial operator+(const Polynomial& poly, double n)
{
	Polynomial r = poly, poly2;

	poly2._c.push_back(n);

	return (r + poly2);
}

Polynomial operator+(double n, const Polynomial& poly)
{
	Polynomial r = poly, poly2;

	poly2._c.push_back(n);

	return (poly2 + r);
}

Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial r = poly1;

	size_t s = poly2._c.size();

	if (r._c.size() < s)
		r._c.resize(s, 0);

	for (size_t i = 0; i < s; i++)
		r._c[i] -= poly2._c[i];

	return r;
}

Polynomial operator-(const Polynomial& poly, double n)
{
	Polynomial r = poly, poly2;

	poly2._c.push_back(n);

	return (r - poly2);
}

Polynomial operator-(double n, const Polynomial& poly)
{
	Polynomial r = poly, poly2;

	poly2._c.push_back(n);

	return (poly2 - r);
}

Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial r;

	int s1 = poly1._c.size(), s2 = poly2._c.size();
	int s = s1 + s2;

	r._c.resize(s, 0);

	for (int i = 0; i < s1; i++)
	{
		for (int j = 0; j < s2; j++)
		{
			r._c[i + j] += poly2._c[j] * poly1._c[i];
		}
	}

	return r;
}

Polynomial operator*(const Polynomial& poly, double n)
{
	Polynomial r = poly;

	for (double& i : r._c)
		i *= n;

	return r;
}

Polynomial operator*(double n, const Polynomial& poly)
{
	Polynomial r = poly;

	for (double& i : r._c)
		i *= n;

	return r;
}

double evaluate(const Polynomial& poly, double var)
{
	double r = 0;
	for (int i = 0; i < poly._c.size(); i++)
		r += poly._c[i] * pow(var, i);
	return r;
}