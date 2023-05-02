// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Observation Diary

#include "Diary.h"

std::string Diary::date;
std::vector<DayLog> Diary::mainLog;

void Diary::NewDay(std::string d)
{
	Diary::date = d;
	DayLog newDay = { date };
	Diary::mainLog.push_back(newDay);
}

void Diary::NewEvent(std::string name, std::string content)
{
	Event newEvent = { name, content };
	Diary::mainLog.back().eventList.push_back({ newEvent });
}