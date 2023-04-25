// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 25, 2023
// Last Update: April 25, 2023
// Problem statement: Prime Number

#pragma once

class PrimeNumber {
public:
	int value;

	PrimeNumber() : value(1) { };

	PrimeNumber(int _value) : value(_value) { };

	inline int get() const { return this->value; };

	inline bool isPrime(int n) const
	{
		for (int i = 2; i <= n / 2; i++)
			if (n % i == 0)
				return false;

		return true;
	}

	PrimeNumber& operator++()
	{
		for (this->value++; !isPrime(this->value); this->value++);
		return (*this);
	}

	PrimeNumber operator++(int)
	{
		PrimeNumber tmp = (*this);
		for (this->value++; !isPrime(this->value); this->value++);
		return tmp;
	}

	PrimeNumber & operator--()
	{
		for (this->value--; !isPrime(this->value); this->value--);
		return (*this);
	}

	PrimeNumber operator--(int)
	{
		PrimeNumber tmp = (*this);
		for (this->value--; !isPrime(this->value); this->value--);
		return tmp;
	}
};