// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: February 23, 2023
// Last Update: February 23, 2023
// Problem statement: Hello World

#include <iostream>

using namespace std;

int main()
{
	const string HELLO_STR = "Hello World!";

	for (;;)
	{
		int n = 0;

		// get n from istream
		cin >> n;

		// if get a EOF from istream
		if (cin.eof())
			break;

		// output the string for n times
		for (size_t i = 0; i < n; i++)
		{
			cout << HELLO_STR << endl;
		}
	}

	return 0;
}