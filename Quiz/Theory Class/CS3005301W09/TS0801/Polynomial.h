// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 24, 2023
// Last Update: April 24, 2023
// Problem statement: Design Polynomial Class

#pragma once

#include <vector>

class Polynomial {
private:
	std::vector<double> _c;
public:
	Polynomial();
	Polynomial(double*, int);
	Polynomial(const Polynomial&);

	int mySize() const;

	Polynomial& operator=(const Polynomial&);
	double& operator[](int);

	friend Polynomial operator+(const Polynomial&, const Polynomial&);
	friend Polynomial operator+(const Polynomial&, double);
	friend Polynomial operator+(double, const Polynomial&);

	friend Polynomial operator-(const Polynomial&, const Polynomial&);
	friend Polynomial operator-(const Polynomial&, double);
	friend Polynomial operator-(double, const Polynomial&);

	friend Polynomial operator*(const Polynomial&, const Polynomial&);
	friend Polynomial operator*(const Polynomial&, double);
	friend Polynomial operator*(double, const Polynomial&);

	friend double evaluate(const Polynomial&, double);
};