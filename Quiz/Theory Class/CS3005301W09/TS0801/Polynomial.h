#pragma once

#include <vector>

class Polynomial {
private:
	std::vector<double> _c;
public:
	Polynomial() { };

	Polynomial(double* param, int size)
	{
		for (int i = 0; i < size; i++)
			this->_c.push_back(param[i]);
	}

	Polynomial(const Polynomial& poly)
	{
		this->_c = poly._c;
	}

	int mySize() const
	{
		for (size_t i = this->_c.size() - 1; i > 0; i--)
			if (this->_c[i] > 0)
				return (i + 1);
	}

	friend Polynomial operator+(const Polynomial& poly1, const Polynomial& poly2)
	{
		Polynomial r = poly1;

		size_t s = poly2.mySize();

		if (r._c.size() < s)
			r._c.resize(s, 0);

		for (size_t i = 0; i < s; i++)
			r._c[i] += poly2._c[i];

		return r;
	}

	friend Polynomial operator+(const Polynomial& poly, double n)
	{
		Polynomial r = poly;

		size_t s = 1;

		if (r._c.size() < s)
			r._c.resize(s, 0);

		r._c[0] += n;

		return r;
	}

	friend Polynomial operator+(double n, const Polynomial& poly)
	{
		Polynomial r = poly;

		size_t s = 1;

		if (r._c.size() < s)
			r._c.resize(s, 0);

		r._c[0] += n;

		return r;
	}

	friend Polynomial operator-(const Polynomial& poly1, const Polynomial& poly2)
	{
		Polynomial r = poly1;

		size_t s = poly2.mySize();

		if (r._c.size() < s)
			r._c.resize(s, 0);

		for (size_t i = 0; i < s; i++)
			r._c[i] -= poly2._c[i];

		return r;
	}

	friend Polynomial operator-(const Polynomial& poly, double n)
	{
		Polynomial r = poly;

		size_t s = 1;

		if (r._c.size() < s)
			r._c.resize(s, 0);

		r._c[0] -= n;

		return r;
	}

	friend Polynomial operator-(double n, const Polynomial& poly)
	{
		Polynomial r = poly;

		size_t s = 1;

		if (r._c.size() < s)
			r._c.resize(s, 0);

		r._c[0] -= n;

		return r;
	}

	friend Polynomial operator*(const Polynomial& poly1, const Polynomial& poly2)
	{
		Polynomial r = poly1;

		int s1 = poly1.mySize(), s2 = poly2.mySize();
		int s = s1 + s2;

		if (r._c.size() < s)
			r._c.resize(s, 0);

		for (int i = 0; i < s1; i++)
		{
			for (int j = 0; j < s2; j++)
			{
				r._c[i + j] += poly2[j] * poly1[i];
			}
		}

		return r;
	}

	friend Polynomial operator*(const Polynomial& poly, double n)
	{
		Polynomial r = poly;

		for (double& i : r._c)
			i *= n;

		return r;
	}

	friend Polynomial operator*(double n, const Polynomial& poly)
	{
		Polynomial r = poly;

		for (double& i : r._c)
			i *= n;

		return r;
	}

	inline double operator[](int index) const
	{
		return this->_c[index];
	}
};

double evaluate(const Polynomial& poly, const double& var)
{
	double r = 0;
	for (int i = 0; i < poly.mySize(); i++)
		r += poly[i] * pow(var, i);
	return r;
}