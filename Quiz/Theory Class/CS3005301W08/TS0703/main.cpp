// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: April 11, 2023
// Last Update: April 11, 2023
// Problem statement: Seven-segment Display

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//     _  _     _  _  _  _  _  _ 
//   | _| _||_||_ |_   ||_||_|| |
//   ||_  _|  | _||_|  ||_| _||_|

map <char, vector<char>> seven = {
	//                     0,   1,   2,   3,   4,   5,   6
	{ '0', vector<char>({ '_', '|', '|', '_', '|', '|', ' ' }) },
	{ '1', vector<char>({ ' ', '|', '|', ' ', ' ', ' ', ' ' }) },
	{ '2', vector<char>({ '_', '|', ' ', '_', '|', ' ', '_' }) },
	{ '3', vector<char>({ '_', '|', '|', '_', ' ', ' ', '_' }) },
	{ '4', vector<char>({ ' ', '|', '|', ' ', ' ', '|', '_' }) },
	{ '5', vector<char>({ '_', ' ', '|', '_', ' ', '|', '_' }) },
	{ '6', vector<char>({ '_', ' ', '|', '_', '|', '|', '_' }) },
	{ '7', vector<char>({ '_', '|', '|', ' ', ' ', ' ', ' ' }) },
	{ '8', vector<char>({ '_', '|', '|', '_', '|', '|', '_' }) },
	{ '9', vector<char>({ '_', '|', '|', '_', ' ', '|', '_' }) }
};

vector<string> getSevgenSegment(char c)
{
	vector<string> r(3);

	if (seven.count(c) == 0)
		return r;

	stringstream ss0, ss1, ss2;
	vector<char> cc = seven[c];
	ss0 << ' ' << cc[0] << ' ';
	ss1 << cc[5] << cc[6] << cc[1];
	ss2 << cc[4] << cc[3] << cc[2];

	r[0] = ss0.str();
	r[1] = ss1.str();
	r[2] = ss2.str();

	return r;
}

vector<string> getMergedSevenSegment(vector<char> cc)
{
	vector<string> r(3);
	for (auto it = cc.begin(); it != cc.end(); it++)
	{
		vector<string> seven = getSevgenSegment(*it);
		r[0] += seven[0];
		r[1] += seven[1];
		r[2] += seven[2];
	}
	return r;
}

int main()
{
	for (string str; getline(cin, str) && !cin.eof();)
	{
		vector<char> chars;
		size_t cNum = 0;
		for (const char& c : str)
			chars.push_back(c);

		vector<string> sevenMerged = getMergedSevenSegment(chars);
		cout 
			<< sevenMerged[0] << endl
			<< sevenMerged[1] << endl
			<< sevenMerged[2] << endl;
	}

	return 0;
}