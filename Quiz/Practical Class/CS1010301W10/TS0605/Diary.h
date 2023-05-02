// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Observation Diary

#pragma once

#include <iostream>
#include <vector>

typedef struct
{
	std::string name;
	std::string content;
}Event;

typedef struct
{
	std::string dayName;
	std::vector<Event> eventList;
}DayLog;

class Diary
{
public:
	static std::vector<DayLog> mainLog;
	static std::string date;

	static void NewDay(std::string);
	static void NewEvent(std::string, std::string);
};