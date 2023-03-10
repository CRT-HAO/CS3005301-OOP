// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 10, 2023
// Last Update: March 10, 2023
// Problem statement: Compute The Tax

#include <iostream>
#include <vector>

using namespace std;

struct TaxRule {
	double start = 0;
	double end = 0;
	double taxStart = 0;
	double amount = 0;
};

const vector<TaxRule> RANGE = {
	TaxRule{0, 749, 0, 0.01},
	TaxRule{750, 2249, 7.5, 0.02},
	TaxRule{2250, 3749, 37.5, 0.03},
	TaxRule{3750, 5249, 82.5, 0.04},
	TaxRule{5250, 6999, 142.5, 0.05},
	TaxRule{7000, INFINITY, 230, 0.06}
};

int main()
{
	for (double n; (cin >> n) && !cin.eof();)
	{
		for (const auto& r : RANGE)
		{
			if (n >= r.start && n <= r.end)
			{
				double tax = r.taxStart;
				tax += (n - r.start) * r.amount;
				cout.precision(2);
				cout << fixed << tax << endl;
				break;
			}
		}
	}

	return 0;
}