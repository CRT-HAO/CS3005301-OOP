// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 2, 2023
// Last Update: May 2, 2023
// Problem statement: Number Game

#include "NumberGame.h"

#include <iostream>

using namespace std;

int main()
{
	NumberGame Game;
	Game.SetInput(1234);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();

	Game.Reset();
	cout << "\n";
	Game.SetInput(2345);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();
}