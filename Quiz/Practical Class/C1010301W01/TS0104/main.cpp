// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: February 23, 2022 
// Last Update: February 23, 2022 
// Problem statement: Input and Output

#include<iostream>
#include<string>

#define DIGITS 10

using namespace std;

int main()
{
	string str;
	for (;;)
	{
		cin >> str;

		// if get a EOF from istream
		if (cin.eof())
			break;

		// if string length less than DIGITS
		if (str.length() < DIGITS)
		{
			size_t space_len = (DIGITS - str.length());
			// insert space to string
			str.insert(str.begin(), space_len, ' ');
		}

		cout << str << endl;
	}
	return 0;
}