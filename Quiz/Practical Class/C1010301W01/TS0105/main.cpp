// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: February 23, 2022 
// Last Update: February 23, 2022 
// Compute Sphere Volume

#include<iostream>
#include<iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

int main()
{
	for (;;)
	{
		double r = 0;

		// get r from istream
		cin >> r;

		// if get a EOF from istream
		if (cin.eof())
			break;

		// calculate the sphere volume
		double result = (4.0 / 3.0) * PI * pow(r, 3);

		// output the volume,
		// and take the decimal point to sixth place
		cout.precision(6);
		cout << fixed << result << endl;
	}

	return 0;
}