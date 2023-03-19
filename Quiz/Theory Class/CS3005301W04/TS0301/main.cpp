// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: March 19, 2023
// Last Update: March 19, 2023
// Problem statement: Occurrenc Counting

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

// Intent: Split input string with space into int vector
// Pre: The variable str is input string
// Post: The function returns the int vector
vector<int> tokenize(string& str)
{
	stringstream ss(str);

	vector<int> r;

	int num;
	while (ss >> num)
		r.push_back(num);

	return r;
}

// Intent: Count list of numbers
// Pre: The variable nums is input int vector
// Post: The function returns number of input interger
map<int, size_t> countNum(vector<int> nums)
{
	map<int, size_t> r;
	for (const auto& i : nums)
	{
		if (!r.count(i))
			r[i] = 0;
		r[i] += 1;
	}
	return r;
}

// Intent: Sort count list
// Pre: The variable counts is count list
// Post: The function returns sorted list
vector<pair<int, size_t>>
sortCountList(map<int, size_t> counts)
{
	vector<pair<int, size_t>> r;

	for (const auto& i : counts)
		r.push_back(pair<int, size_t>(i.first, i.second));

	sort(
		r.begin(),
		r.end(),
		[](pair<int, size_t>& a, pair<int, size_t>& b)
		{ return a.first > b.first; }
	);

	return r;
}

int main()
{
	// Get line of string from istream, until EOF
	for (string str;(getline(cin, str) && !cin.eof());)
	{
		// Tokenize Input String
		vector<int> list = tokenize(str);

		// Count the list of numbers
		map<int, size_t> counts = countNum(list);

		// Sort the list
		vector<pair<int, size_t>> sorted = sortCountList(counts);

		// Output Result
		cout << "N" << '\t' << "count" << endl;
		for (auto& i : sorted)
			cout << i.first << '\t' << i.second << endl;
	}

	return 0;
}