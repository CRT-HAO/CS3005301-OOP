// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 10, 2023
// Last Update: March 10, 2023
// Problem statement: Square Code

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	for (string str; (cin >> str) && !cin.eof();)
	{
		unsigned int n = ceil(sqrt(str.length()));

		vector<string> square(n);

		// Insert char to square string vector
		for (size_t i = 0; i < str.length(); i++)
			square[i % n].push_back(str[i]);

		// Output the result
		for (auto i : square)
			cout << i << endl;
	}

	return 0;
}