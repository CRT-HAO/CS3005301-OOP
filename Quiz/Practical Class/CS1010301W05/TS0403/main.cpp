// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: March 27, 2023
// Last Update: March 27, 2023
// Problem statement: Greatest Common Divisor

#include <iostream>

using namespace std;

// Indent: Get gcd of numeric a and b
// Pre: The variables of a and b are interger
// Post: The function returns the gcd of a and b
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
	for (int a, b; (cin >> a >> b) && !cin.eof();)
		cout << gcd(a, b) << endl;

	return 0;
}