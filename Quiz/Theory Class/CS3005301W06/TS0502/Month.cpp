// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Design Month Class

#include "Month.h"

const std::vector<std::string> ALL_MONTH = {
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"Jun",
		"Jul",
		"Aug",
		"Sep",
		"Oct",
		"Nov",
		"Dec"
};

Month::Month()
{
	this->month = 0;
}

Month::Month(char first, char second, char third)
{
	int month = Month::parseMonthStrToInt(first, second, third);
	this->month = (month != -1) ? month : 0;
}

Month::Month(int monthInt)
{
	this->month = (monthInt >= 1 && monthInt <= 12) ? (monthInt - 1) : 0;
}


Month::~Month() { }

void Month::inputInt()
{
	int input;
	std::cin >> input;
	this->month = (input >= 1 && input <= 12) ? (input - 1) : 0;
}

void Month::inputStr()
{
	char first, second, third;
	std::cin >> first >> second >> third;
	int month = Month::parseMonthStrToInt(first, second, third);
	this->month = (month != -1) ? month : 0;
}

void Month::outputInt()
{
	std::cout << (this->month + 1);
}

void Month::outputStr()
{
	std::cout << ALL_MONTH[this->month];
}

Month Month::nextMonth()
{
	return Month(this->month + 1 + 1);
}

int Month::parseMonthStrToInt(char first, char second, char third)
{
	for (size_t i = 0; i < ALL_MONTH.size(); i++)
		if (ALL_MONTH[i][0] == first &&
			ALL_MONTH[i][1] == second &&
			ALL_MONTH[i][2] == third)
			return i;

	return -1;
}