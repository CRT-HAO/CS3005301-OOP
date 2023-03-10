// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: March 10, 2023
// Last Update: March 10, 2023
// Problem statement: Leaderboard

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Intent: To get top 3 of high scores
// Pre: The variable name is a list of name, score is a list of score
// Post: The function returns the list of top 3 of high scores
vector<pair<string, long>>
getHighScores(vector<string> name, vector<long> score)
{
	// Create a vector for a pair of name and score
	vector<pair<string, long>> r;
	for (size_t i = 0; i < name.size(); i++)
		r.push_back(pair<string, long>(name[i], score[i]));

	// Sort the vector with score
	sort(
		r.begin(),
		r.end(),
		[](pair<string, long> a, pair<string, long> b)
		{ return a.second > b.second; }
	);

	r.resize(3);

	return r;
}

int main()
{
	// Open scores file, and exit if opening failed
	ifstream ifs;
	ifs.open("scores.txt");
	if (ifs.fail()) {
		cout << "input file opening failed";
		exit(1);
	}

	// Read name and score to vector
	vector<string> name;
	vector<long> score;
	for (size_t i = 0; !ifs.eof();)
	{
		string str;
		ifs >> str;

		if (str.empty())
			continue;

		if (i % 2 == 0)
			name.push_back(str);
		else
			score.push_back(stoi(str));

		i++;
	}

	// Get top 3 high scores
	vector<pair<string, long>> list = getHighScores(name, score);

	// Output result
	for (auto& n : list)
	{
		auto i = &n - &list[0];
		cout << n.first << endl << n.second;
		if(i != list.size() - 1)
			cout << endl;
	}

	return 0;
}