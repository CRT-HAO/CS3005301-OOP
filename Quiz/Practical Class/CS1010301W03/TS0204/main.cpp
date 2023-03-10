// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 10, 2023
// Last Update: March 10, 2023
// Problem statement: Print Standard Format

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct Data for save single data
struct Data {
	string name;
	unsigned int salary = 0;
	unsigned int award = 0;
};

// Intent: Make the string a specified length, 
//		   and use space compensation for deficiencies
// Pre: The variable str is original string, width is target width
// Post: The function returns the string with spaces
string getStringWithSpaces(string str, size_t width = 0)
{
	if (str.length() > width)
		return str;

	return string(width - str.length(), ' ') + str;
}

int main()
{
	// Get n from istream, break if get a EOF 
	for (unsigned int n; (cin >> n) && !cin.eof();)
	{
		vector<Data> elems;
		size_t maxNameLength = 0, maxSalaryLength = 0, maxAwardLength = 0;

		// Get data n times from istream
		for (size_t i = 0; !cin.eof() && i < n; i++)
		{
			string name, salary, award;

			cin >> name >> salary >> award;

			struct Data data;

			data.name = name;
			data.salary = stoi(salary);
			data.award = stoi(award);

			elems.push_back(data);

			// Set max length
			if (name.length() > maxNameLength)
				maxNameLength = name.length();
			if (salary.length() > maxSalaryLength)
				maxSalaryLength = salary.length();
			if (award.length() > maxAwardLength)
				maxAwardLength = award.length();
		}

		// Output result
		for (auto i : elems)
			cout << getStringWithSpaces(i.name, maxNameLength)
				<< "|  "
				<< getStringWithSpaces(to_string(i.salary), maxSalaryLength)
				<< "|  "
				<< getStringWithSpaces(to_string(i.award), maxAwardLength)
				<< endl;
	}

	return 0;
}