// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: February 23, 2023
// Last Update: February 24, 2023
// Problem statement: Compute HMS

#include <iostream>
#include <cmath> // floor

using namespace std;

int main()
{
	for (;;)
	{
		uint64_t n = 0;

		// get time in seconds from istream
		cin >> n;

		// if get a EOF from istream
		if (cin.eof())
			break;

		uint64_t hours = 0, minutes = 0, seconds = 0;

		// calculate the HMS
		seconds = n % 60;
		minutes = n / 60;
		hours = minutes / 60;
		minutes = minutes % 60;

		// output the result(HMS)
		cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds" << endl;
	}

	return 0;
}