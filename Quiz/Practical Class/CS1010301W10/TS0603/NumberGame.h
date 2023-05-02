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
	std::string inputNumber;
	std::string fileName;
	std::set<int> allCombination;
	std::vector<int> validNumber;

public:
	NumberGame() { }

	inline void SetInput(int input)
	{ inputNumber = std::to_string(input); }

	void ProcessInput()
	{
		for (const auto& c : inputNumber)
		{
			// Change data type
			int digit = (int)(c - '0');
			// Create a temp set
			std::set<int> temp;
			// Multiply current digit with every element in validNumber
			for (const auto& i : allCombination)
				temp.insert(i * digit);
			// Insert digit
			allCombination.insert(digit);
			// Insert all combination of current digit
			allCombination.insert(temp.begin(), temp.end());
		}
	}

	inline void SetFileName(std::string input)
	{ fileName = input; }

	void LoadNumberList()
	{
		std::ifstream fin(fileName);
		for (int input; fin >> input;)
			if (allCombination.count(input))
				validNumber.push_back(input);

		fin.close();
	}

	inline void PrintAllValid() const
	{
		for (const auto& number : validNumber)
			std::cout << number << std::endl;
	}

	inline void Reset()
	{
		inputNumber.clear();
		fileName.clear();
		validNumber.clear();
		allCombination.clear();
	}
};