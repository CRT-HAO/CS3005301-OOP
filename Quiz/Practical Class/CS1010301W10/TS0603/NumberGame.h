// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 2, 2023
// Last Update: May 2, 2023
// Problem statement: Number Game

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

class NumberGame
{
private:
	std::string _inputNumber;
	std::string _fileName;
	std::set<int> _allCombination;
	std::vector<int> _validNumber;

public:
	NumberGame() { }

	inline void SetInput(int input)
	{ this->_inputNumber = std::to_string(input); }

	void ProcessInput()
	{
		for (const char& c : this->_inputNumber)
		{
			int digit = (int)(c - '0');
			std::set<int> temp;
			for (const int& i : this->_allCombination)
				temp.insert(i * digit);

			this->_allCombination.insert(digit);
			this->_allCombination.insert(temp.begin(), temp.end());
		}
	}

	inline void SetFileName(std::string input)
	{ this->_fileName = input; }

	void LoadNumberList()
	{
		std::ifstream fin(this->_fileName);
		for (int input; fin >> input;)
			if (this->_allCombination.count(input))
				this->_validNumber.push_back(input);

		fin.close();
	}

	inline void PrintAllValid() const
	{
		for (const int& number : this->_validNumber)
			std::cout << number << std::endl;
	}

	inline void Reset()
	{
		this->_inputNumber.clear();
		this->_fileName.clear();
		this->_validNumber.clear();
		this->_allCombination.clear();
	}
};