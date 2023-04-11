// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: April 11, 2023
// Last Update: April 11, 2023
// Problem statement: FormWord

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

class Form
{
private:
	string _word;
	map<char, size_t> _wordMap;
	string _filename;
	vector<string> _compareWords;
	vector<string> _foundWords;
	static string _toLower(const string& str);

public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};

string Form::_toLower(const string& str)
{
	string r = str;
	std::transform(r.begin(), r.end(), r.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return r;
}

void Form::SetInputWord(string inputWord)
{
	this->_word = inputWord;
}

void Form::ProcessInputWord()
{
	this->_wordMap.clear();
	string word = Form::_toLower(this->_word);
	for (const char& c : word) {
		this->_wordMap[c] += 1;
	}
}

void Form::SetFileName(string filename)
{
	this->_filename = filename;
}

void Form::Load_CompareWord()
{
	ifstream ifs;

	ifs.open(this->_filename);

	if (ifs.fail())
		throw "Load Compare Words File Failed";

	this->_compareWords.clear();
	for (string line; getline(ifs, line) && !ifs.eof();)
		this->_compareWords.push_back(line);

	ifs.close();

	this->_foundWords.clear();
	for (const string& i : this->_compareWords)
	{
		string s = Form::_toLower(i);
		map<char, size_t> cNum;
		bool compare = true;
		for (const char& c : s)
		{
			if ((cNum[c] += 1) > this->_wordMap[c])
			{
				compare = false;
				break;
			}
		}

		if(compare)
			this->_foundWords.push_back(i);
	}
}

void Form::PrintFoundWords()
{
	for (const string& i : this->_foundWords)
		cout << i << endl;
}