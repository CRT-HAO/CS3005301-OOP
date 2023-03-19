// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 19, 2023
// Last Update: March 19, 2023
// Problem statement: Text-based histogram

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

// Intent: Split input string with space into int vector
// Pre: The variable str is input string
// Post: The function returns the int vector
vector<unsigned int> tokenize(string& str)
{
	stringstream ss(str);

	vector<unsigned int> r;

	unsigned int num;
	while (ss >> num)
		r.push_back(num);

	return r;
}

// Intent: Count list of numbers
// Pre: The variable nums is input int vector
// Post: The function returns number of input interger
map<unsigned int, size_t> countNum(vector<unsigned int> nums)
{
	map<unsigned int, size_t> r;
	for (const auto& i : nums)
	{
		if (!r.count(i))
			r[i] = 0;
		r[i] += 1;
	}
	return r;
}

int main()
{
	ifstream ifs;
	ofstream ofs;

	ifs.open("grade.txt");
	if(ifs.fail()) {
		cout << "Input file opening failed";
		exit(1);
	}

	ofs.open("grades.Output");
	if (!ofs.is_open()) {
		cout << "Output file opening failed";
		return 1;
	}

	// Get line of string from ifstream, until EOF
	for (string str; (getline(ifs, str) || !ifs.eof());)
	{
		// Tokenize input string
		vector<unsigned int> list = tokenize(str);

		// Get max num in the list
		unsigned int max_num =
			*max_element(list.begin(), list.end());

		// Count the list of numbers
		map<unsigned int, size_t> counts = countNum(list);

		// Output result
		for (size_t i = 0; i < max_num + 1; i++)
		{
			stringstream ss;
			ss << counts[i] << " grade(s) of " << i;

			if (i != max_num)
				ss << endl;

			cout << ss.str();
			ofs << ss.str();
		}
	}

	return 0;
}