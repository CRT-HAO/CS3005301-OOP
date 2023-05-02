// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Observation Diary

#pragma once

#include "Diary.h"

#include <string>
#include <map>
#include <iostream>
#include <sstream>

class Creature
{
private:
	std::string _name;
	std::map<std::string, int> _bodyPart;
	std::string _partIndex;
	int _birthdayIndex;

	std::string _generateMessage(int old, int now)
	{
		std::stringstream ss;
		ss << this->_name << "'s " << this->_partIndex << ' ';
		if (old == 0 && now > 0)
			ss << "appeared ";
		else if (old > now)
			ss << "decreased ";
		else if (old < now)
			ss << "increased ";
		else if (old == now)
			return "";
		ss << '(' << old << " -> " << now << ")." << std::endl;
		return ss.str();
	}

public:
	Creature(std::string name) :_name(name)
	{ this->_birthdayIndex = Diary::mainLog.size() - 1; }

	Creature(std::string name, Creature base) : _name(name)
	{
		for (const auto& part : base._bodyPart)
			this->_bodyPart[part.first] = part.second;
		this->_birthdayIndex = Diary::mainLog.size() - 1;
	}

	void PrintStatus() const
	{
		std::cout << this->_name << "'s status:" << std::endl;
		for (const auto& part : this->_bodyPart)
			if (part.second != 0)
				std::cout << part.first << " * " << part.second << std::endl;

		std::cout << std::endl;
	}

	void PrintLog() const
	{
		std::cout << this->_name << "'s log:" << std::endl;
		for (int i = this->_birthdayIndex; i < Diary::mainLog.size(); i++)
		{
			std::cout << "Day " << Diary::mainLog[i].dayName << std::endl;
			for (const Event& e : Diary::mainLog[i].eventList)
			{
				if (e.name == this->_name)
					std::cout << e.content;
			}
		}
		std::cout << std::endl;
	}

	Creature& operator[](std::string key)
	{
		this->_partIndex = key;
		if (this->_bodyPart.find(key) == this->_bodyPart.end())
			this->_bodyPart[key] = 0;

		return (*this);
	}

	void operator=(int number)
	{
		int old = this->_bodyPart[this->_partIndex];
		this->_bodyPart[this->_partIndex] = number;

		std::string record =
			this->_generateMessage(old, this->_bodyPart[this->_partIndex]);

		if (record.size() == 0)
			return;

		Diary::NewEvent(this->_name, record);
	}

	void operator+=(int number)
	{
		int old = this->_bodyPart[this->_partIndex];
		this->_bodyPart[this->_partIndex] += number;

		std::string record =
			this->_generateMessage(old, this->_bodyPart[this->_partIndex]);

		if (record.size() == 0)
			return;

		Diary::NewEvent(this->_name, record);
	}

	void operator-=(int number)
	{
		int old = this->_bodyPart[this->_partIndex];
		this->_bodyPart[this->_partIndex] -= number;

		std::string record =
			this->_generateMessage(old, this->_bodyPart[this->_partIndex]);

		if (record.size() == 0)
			return;

		Diary::NewEvent(this->_name, record);
	}
};