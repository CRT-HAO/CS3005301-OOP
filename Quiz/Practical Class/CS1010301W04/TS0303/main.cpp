// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: March 20, 2023
// Last Update: March 20, 2023
// Problem statement: Input_Output3

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Intent: Resize num string to target decmial point digits
// Pre: The variable num is num string,
//		digits is target decmial point digits
// Post: The function returns resized num string
string resizeWithDigits(string num, size_t digits)
{
	string r = num;

	if (r.find('.') == -1 && digits > 0)
		r.push_back('.');

	size_t decimalPointPos = r.find('.');
	size_t decimalPointDigits = r.length() - decimalPointPos - 1;
	size_t decimalDigits = r.length() - decimalPointDigits - 1;

	if (digits == 0)
	{
		if (decimalPointPos != string::npos)
			r.resize(decimalPointPos, '0');
	}
	else
		r.resize(decimalDigits + digits + 1, '0');

	return r;
}

// Intent: Fill string to target length with char
// Pre: The variable str is src string,
//		length is target length, c is char
// Post: The function returns filled string
string fillString(string str, size_t length, char c)
{
	string r = str;

	if (str.length() >= length)
		return r;

	r = string(length - str.length(), c) + r;

	return r;
}

int main()
{
	// Get line of string rom istream
	for (string str; getline(cin, str) && !cin.eof();)
	{
		// Save input string into stringstream
		stringstream ss(str);

		string x;
		unsigned int m, n;
		char c;

		// Break when shift stringstream
		// into variables failed
		if (!(ss >> x >> m >> n >> c))
			break;

		// Resize string x with target decmial
		// point digits
		x = resizeWithDigits(x, n);

		// Fill string x to target length with
		// char c
		x = fillString(x, m, c);

		// Output result
		cout << x << endl;
	}

	return 0;
}