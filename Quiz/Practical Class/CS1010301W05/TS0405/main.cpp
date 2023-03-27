// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 27, 2023
// Last Update: March 27, 2023
// Problem statement: Collatz Conjecture

#include <iostream>

using namespace std;

// Indent: Get Collatz Conjecture Length with n
// Pre: The variables n is a interger, times is the start length
// Post: The function returns the length of Collatz Conjecture n
size_t collatzConjectureLength(int n, size_t times = 1)
{
	return (
		(n == 1) ? times :
		collatzConjectureLength((n % 2 == 0) ? n / 2 : n * 3 + 1, times + 1)
		);
}

int main()
{
	// Get interger a and b from istream, until get an EOF
	for (int a, b; (cin >> a >> b) && !cin.eof();)
	{
		size_t maxLength = 0;
		int startNum = min(a, b);
		int endNum = max(a, b);
		// Get Collatz Conjecture length from the bigger num to smaller num
		for (int i = 0; i < endNum - startNum + 1; i++)
		{
			size_t length = collatzConjectureLength(startNum + i);
			// Set max length if the length bigger than max length 
			if (length > maxLength)
				maxLength = length;
		}

		// Output Result
		cout << a << ' ' << b << ' ' << maxLength << endl;
	}
	return 0;
}