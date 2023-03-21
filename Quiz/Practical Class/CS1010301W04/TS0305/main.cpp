// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 21, 2023
// Last Update: March 21, 2023
// Problem statement: Simple Drawing Program

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define BACKGROUND_CHAR '*'
#define FILL_CHAR 'X'

using namespace std;

typedef vector<vector<char>> Board;

// Indent: Print the board to console
// Pre: The variable board is board data
void printBoard(Board &board)
{
	for (const auto& i : board)
	{
		for (const auto& j : i)
			cout << j;

		cout << endl;
	}
}

// Indent: Draw Square
// Pre: The variable x and y is the position,
//		width is width of square, board is board data
// Post: Return true is draw successful
bool drawSquare(int x, int y, int width, Board &board)
{
	size_t boardWidth = board[0].size();
	size_t boardHeight = board.size();

	// If target shape out of range, return false
	if ((x < 0 || (x + width - 1) >= boardWidth) ||
		(y < 0 || (y + width - 1) >= boardHeight))
		return false;

	// Draw Square with FILL_CHAR
	for (size_t iY = 0; iY < width; iY++)
		for (size_t iX = 0; iX < width; iX++)
			board[y + iY][x + iX] = FILL_CHAR;

	return true;
}

// Indent: Draw Triangle
// Pre: The variable x and y is the position,
//		width is width of traingle,
//		type is the type of traingle [LU/LD/RU/RD]
//		board is board data
// Post: Return true is draw successful
bool drawTriangle(int x, int y, int width, unsigned char type, Board& board)
{
	size_t boardWidth = board[0].size();
	size_t boardHeight = board.size();

	size_t n = width;

	char xDir, yDir;

	switch (type)
	{
	// Lef Up
	default:
	case 0:
		xDir = -1, yDir = -1;
		break;
	// Left Down
	case 1:
		xDir = -1, yDir = 1;
		break;
	// Right Up
	case 2:
		xDir = 1, yDir = -1;
		break;
	// Right Down
	case 3:
		xDir = 1, yDir = 1;
		break;
	}

	// If target shape out of range, return false
	if ((x < 0) || (x >= boardWidth) ||
		(y < 0) || (y >= boardHeight) ||
		(x + (((int)width - 1) * xDir) < 0) ||
		(x + (((int)width - 1) * xDir) >= boardWidth) ||
		(y + (((int)width - 1) * yDir) < 0) ||
		(y + ((int)width * yDir) >= boardHeight))
		return false;

	// Draw Square with FILL_CHAR
	for (size_t iY = 0; iY < width; iY++)
	{
		for (size_t iX = 0; iX < n; iX++)
			board[y + (iY * yDir)][x + (iX * xDir)] = FILL_CHAR;

		n--;
	}

	return true;
}

// Indent: Draw Line
// Pre: The variable x1 and y1 are the start position,
//		x2 and y2 are end position, board is board data
// Post: Return true is draw successful
bool drawLine(int x1, int y1, int x2, int y2, Board &board)
{
	size_t boardWidth = board[0].size();
	size_t boardHeight = board.size();

	int dx = x2 - x1;
	int dy = y2 - y1;

	size_t xWidth = max(x1, x2) - min(x1, x2) + 1;
	size_t yWidth = max(y1, y2) - min(y1, y2) + 1;

	unsigned int n = abs(max(dx, dy));

	double xinc = (double)dx / n, yinc = (double)dy / n;

	double x = x1, y = y1;

	// If target shape out of range, return false
	if ((x1 < 0 || x1 >= boardWidth) ||
		(x2 < 0 || x2 >= boardWidth) ||
		(y1 < 0 || y1 >= boardHeight) ||
		(y2 < 0 || y2 >= boardHeight))
		return false;

	// Draw Square with FILL_CHAR
	for (size_t i = 0; i < max(xWidth, yWidth); i++)
	{
		board[floor(y)][floor(x)] = FILL_CHAR;
		x += xinc;
		y += yinc;
	}

	return true;
}

int main()
{

	int m, n;

	// Get board size from istream
	cin >> m >> n;

	// Create board
	Board board(n, vector<char>(m, BACKGROUND_CHAR));

	// Get mode and data from istream until get an EOF
	for (string mode; (cin >> mode) && !cin.eof();)
	{
		// If get "EXIT" then stop
		if (mode == "EXIT")
			break;

		// Draw by target mode function
		switch (mode[0])
		{

		// Square
		case 'S':
		{
			int width, x, y;
			cin >> width >> x >> y;
			if (drawSquare(x, y, width, board))
			{
				printBoard(board);
				cout << endl;
			}
			else
				cout << "Out of range." << endl << endl;
		}break;

		// Triangle
		case 'T':
		{
			int width, x, y;
			string type;
			cin >> width >> x >> y >> type;

			unsigned char typeN = 0;
			if (type == "LU")
				typeN = 0;
			else if (type == "LD")
				typeN = 1;
			else if (type == "RU")
				typeN = 2;
			else if (type == "RD")
				typeN = 3;

			if (drawTriangle(x, y, width, typeN, board))
			{
				printBoard(board);
				cout << endl;
			}
			else
				cout << "Out of range." << endl << endl;
		}break;

		// Line
		case 'L':
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (drawLine(x1, y1, x2, y2, board))
			{
				printBoard(board);
				cout << endl;
			}
			else
				cout << "Out of range." << endl << endl;
		}break;

		}
	}

	return 0;

}