// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: March 10, 2023
// Last Update: March 10, 2023
// Problem statement: Computes the average and standard deviation

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// Intent: Calculate Standard Deviation
// Pre: The variable s is a vector of s, and avg is average.
// Post: The function returns the standard deviation
double calculateStandardDeviation(vector<double> s, double avg)
{
	double r = 0;
	double m = avg;
	for (auto si : s)
		r += pow(si - m, 2);

	return r = sqrt(r / s.size());
}

int main()
{
	int n = 0;
	// Get n from istream, break when get an EOF
	while ((cin >> n) && !cin.eof())
	{
		// Get n number from istream and save in vector s
		vector<double> s;
		for (size_t i = 0; i < n; i++)
		{
			double tmp = 0;
			cin >> tmp;
			s.push_back(tmp);
		}

		// Calculate average
		double avg = accumulate(s.begin(), s.end(), 0.0) / n;
		// Calculate standard deviation
		double standaedDeviation = calculateStandardDeviation(s, avg);

		// Output result
		cout << "Average:" << avg << "\t" << "Standard deviation:" << standaedDeviation << endl;
	}

	return 0;
}