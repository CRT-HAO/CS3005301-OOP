// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 14, 2023
// Last Update: April 14, 2023
// Problem statement: Large Interger Operation

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt {
private:
	vector<char> _num;
	bool _negative;
	static bool _isSmaller(const vector<char>& num1, const vector<char>& num2);
public:
	BigInt() : _negative(false) { }
	BigInt(const vector<char>& num) : _num(num), _negative(false) { }
	BigInt(const string& num);
	void set(const string& num);
	void set(const vector<char>& num);
	string toStr() const;
	BigInt operator+(const BigInt& num);
	BigInt operator-(const BigInt& num);
	BigInt operator*(const BigInt& num);
};

bool BigInt::_isSmaller(const vector<char>& num1, const vector<char>& num2) {
	size_t n1 = num1.size(), n2 = num2.size();

	if (n1 < n2)
		return true;
	if (n1 > n2)
		return false;

	for (size_t i = 0; i < n1; i++) {
		if (num1[i] < num2[i])
			return true;
		else if (num1[i] > num2[i])
			return false;
	}

	return false;
}

BigInt::BigInt(const string& num) {
	this->_negative = false;
	for (const char& i : num)
		this->_num.push_back((char)i - '0');
}

void BigInt::set(const string& num) {
	this->_negative = false;
	this->_num.clear();
	for (const char& i : num)
		this->_num.push_back((char)i - '0');
}

void BigInt::set(const vector<char>& num) {
	this->_negative = false;
	this->_num.clear();
	this->_num = num;
}

string BigInt::toStr() const {
	string r;
	bool start = false;
	for (const char& i : this->_num) {
		if (i != 0 || start) {
			r.push_back(i + '0');
			start = true;
		}
	}

	if (r.size() == 0)
		return "0";

	if (this->_negative)
		r = '-' + r;

	return r;
}

BigInt BigInt::operator+(const BigInt& num) {
	BigInt ri;
	vector<char> r;
	vector<char> num1 = this->_num;
	vector<char> num2 = num._num;

	if (!_isSmaller(num1, num2))
		swap(num1, num2);

	size_t n1 = num1.size(), n2 = num2.size();

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int carry = 0;
	for (size_t i = 0; i < n1; i++) {
		int sum = num1[i] + num2[i] + carry;
		carry = sum / 10;
		sum %= 10;
		r.push_back(sum);
	}

	for (size_t i = n1; i < n2; i++) {
		int sum = num2[i] + carry;
		carry = sum / 10;
		sum %= 10;
		r.push_back(sum);
	}

	if (carry)
		r.push_back(carry);

	reverse(r.begin(), r.end());

	ri.set(r);

	return ri;
}

BigInt BigInt::operator-(const BigInt& num) {
	BigInt ri;
	vector<char> r;
	vector<char> num1 = this->_num;
	vector<char> num2 = num._num;

	bool negative = false;

	if(_isSmaller(num1, num2))
		negative = true;

	if (!_isSmaller(num1, num2))
		swap(num1, num2);

	size_t n1 = num1.size(), n2 = num2.size();

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	num1.resize(n2, 0);

	int carry = 0;
	for (size_t i = 0; i < n2; i++) {
		int sub = num2[i] - num1[i] - carry;
		if (sub < 0) {
			sub += 10;
			carry = 1;
		}
		else
			carry = 0;
		r.push_back(sub);
	}

	reverse(r.begin(), r.end());

	ri.set(r);
	ri._negative = negative;

	return ri;
}

BigInt BigInt::operator*(const BigInt& num) {
	BigInt ri;
	vector<char> r;
	vector<char> num1 = this->_num;
	vector<char> num2 = num._num;

	size_t n1 = num1.size(), n2 = num2.size();

	r.resize(n1 + n2, 0);

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	for (size_t i = 0; i < n1; i++) {
		int carry = 0;
		for (size_t j = 0; j < n2; j++) {
			int sum = num1[i] * num2[j] + r[i + j] + carry;
			carry = sum / 10;
			r[i + j] = sum % 10;
		}
		if (carry > 0)
			r[i + n2] += carry;
	}

	reverse(r.begin(), r.end());

	ri.set(r);

	return ri;
}