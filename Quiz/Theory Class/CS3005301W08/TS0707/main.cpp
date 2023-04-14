// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 14, 2023
// Last Update: April 14, 2023
// Problem statement: Large Interger Operation

#include <iostream>

#include "BigInt.hpp"

using namespace std;

int main() {
	for (string num1, num2; (cin >> num1 >> num2) && !cin.eof();) {
		BigInt n1(num1);
		BigInt n2(num2);

		BigInt sum = n1 + n2;
		BigInt diff = n1 - n2;
		BigInt mul = n1 * n2;

		cout
			<< sum.toStr() << endl
			<< diff.toStr() << endl
			<< mul.toStr() << endl;
	}

	return 0;
}