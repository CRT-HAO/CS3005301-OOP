// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 21, 2023
// Last Update: March 21, 2023
// Problem statement: CPU bit growth

#include <iostream>
#include <cmath>

using namespace std;

const unsigned int START_YEAR = 1900;

int main()
{

	// Get input year from istream until get an EOF
	for (unsigned int input; (cin >> input) && !cin.eof();)
	{
		// Calculate current year bits
		unsigned int currentBits = pow(2, ((input - START_YEAR) / 10) + 2);

		// Calculate current years max interger in log10
		double maxIntLog = log10(2) * currentBits;

		// Calculate factorial in log10
		double countLog = 0;
		unsigned int result = 0;
		while (countLog < maxIntLog)
		{
			result++;
			countLog += log10(result);
		}
		// Change to last value
		result -= 1;

		// Output result
		cout << result << endl;
	}

}