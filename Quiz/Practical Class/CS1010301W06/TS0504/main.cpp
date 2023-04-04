// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 4, 2023
// Last Update: April 5, 2023
// Problem statement: Sudoku Checker

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<vector<uint8_t>> Board;

// Indent: Split string to vector using delimiter
// Pre: The variables str is input string
// Post: The function returns split vector of string
vector<string> split(const string& str, char delimiter)
{
	vector<string> r;
	stringstream ss(str);
	for (string tok; getline(ss, tok, delimiter);)
		r.push_back(tok);

	return r;
}

// Indent: Check if sudoku rows valid
// Pre: The variable sudoku is input sudoku board
// Post: The function returns true if all rows valid
bool checkAllRowsValid(const Board& sudoku)
{
	for (size_t i = 0; i < sudoku.size(); i++)
	{
		map<uint8_t, size_t> rowMap;
		for (size_t j = 0; j < sudoku[0].size(); j++)
			rowMap[sudoku[i][j]] += 1;

		for (size_t i = 0; i < 9; i++)
			if (rowMap[i + 1] != 1)
				return false;
	}
	return true;
}

// Indent: Check if sudoku colums valid
// Pre: The variable sudoku is input sudoku board
// Post: The function returns true if all colums valid
bool checkAllColsValid(const Board& sudoku)
{
	for (size_t i = 0; i < sudoku.size(); i++)
	{
		map<uint8_t, size_t> colMap;
		for (size_t j = 0; j < sudoku[0].size(); j++)
			colMap[sudoku[j][i]] += 1;

		for (size_t i = 0; i < 9; i++)
			if (colMap[i + 1] != 1)
				return false;
	}
	return true;
}

// Indent: Extract rectangle from sudoku
// Pre: The variable sudoku is input sudoku board, startX, startY
//      and endX, endY are start and end x, y cordiations
// Post: The function returns the extracted board in 1D vector
vector<uint8_t> extractRectangle(const Board& sudoku,
	size_t startX, size_t startY, size_t endX, size_t endY)
{
	size_t width = endX - startX;
	size_t height = endY - startY;

	vector<uint8_t> r;

	for (size_t iY = 0; iY < height; iY++)
		for (size_t iX = 0; iX < width; iX++)
			r.push_back(sudoku[iY + startY][iX + startX]);

	return r;
}

// Indent: Check if sudoku square valid
// Pre: The variable square is extracted square 1D vector
// Post: The function returns true if the square valid
bool checkSquareValid(const vector<uint8_t>& square)
{
	map<uint8_t, size_t> m;
	for (const auto& i : square)
		m[i] += 1;

	for (size_t i = 0; i < 9; i++)
		if (m[i + 1] != 1)
			return false;

	return true;
}

// Indent: Check if all sudoku squares valid
// Pre: The variable sudoku is input sudoku board
// Post: The function returns true is all squares valid
bool checkAllSquareValid(const Board& sudoku)
{
	const size_t WIDTH = 3;
	for (size_t i = 0; i < WIDTH; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			size_t x = j * WIDTH;
			size_t y = i * WIDTH;
			bool valid = checkSquareValid(
				extractRectangle(sudoku, x, y, x + WIDTH, y + WIDTH));
			if (!valid)
				return false;
		}
	}

	return true;
}

int main()
{
	string s;
	do
	{
		Board sudoku;
		for (size_t i = 0; i < 9; i++)
		{
			string str;
			getline(cin, str);

			vector<string> row = split(str, ',');
			vector<uint8_t> numRow;
			for (const auto& i : row)
				numRow.push_back(stoi(i));

			sudoku.push_back(numRow);
		}

		bool valid = checkAllRowsValid(sudoku) &&
			checkAllColsValid(sudoku) &&
			checkAllSquareValid(sudoku);

		cout << (valid ? "True" : "False") << endl;
	} while (getline(cin, s) && !cin.eof());

	return 0;
}