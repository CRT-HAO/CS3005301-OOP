// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Design Month Class

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Month
{
public:
	Month();

	// Pre: The variable first, second, third
	//      is the first three chars of month
	Month(char first, char second, char third);

	// Pre: The variable monthInt is the month number (1~12)
	Month(int monthInt);

	~Month();

	// Indent: Input month number (1~12) from istream
	void inputInt();

	// Indent: Input month first three chars from istream
	void inputStr();

	// Indent: Print month number to ostream
	void outputInt();

	// Indent: Print month first three chars to ostream
	void outputStr();

	// Indent: Get the object of next month
	// Post: The function returns the month object of next month
	Month nextMonth();
private:
	int month;
	static int parseMonthStrToInt(char first, char second, char third);
};

