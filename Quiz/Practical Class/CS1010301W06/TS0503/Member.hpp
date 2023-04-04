// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 4, 2023
// Last Update: April 4, 2023
// Problem statement: Student Records

#pragma once

#include <iostream>
#include <string>

typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

class Member
{
public:
	Member()
	{
		this->_data = StRec{};
	}

	bool setFirstName(std::string firstName)
	{
		if (!(Member::isFirstNameValid(firstName)))
			return false;

		strcpy_s(this->_data.firstName, firstName.c_str());

		return true;
	}

	bool setLastName(std::string lastName)
	{
		if (!(Member::isLastNameValid(lastName)))
			return false;

		strcpy_s(this->_data.lastName, lastName.c_str());

		return true;
	}

	bool setPhone(std::string phone)
	{
		if (!(Member::isPhoneValid(phone)))
			return false;

		strcpy_s(this->_data.phone, phone.c_str());

		return true;
	}

	std::string getFirstName()
	{
		return this->_data.firstName;
	}

	std::string getLastName()
	{
		return this->_data.lastName;
	}

	std::string getPhone()
	{
		return this->_data.phone;
	}

	static bool isFirstNameValid(const std::string& firstName)
	{
		return (firstName.length() <= 25);
	}

	static bool isLastNameValid(const std::string& lastName)
	{
		return (lastName.length() <= 30);
	}

	static bool isPhoneValid(const std::string& phone)
	{
		return (phone.length() <= 15 && Member::isNumber(phone));
	}
private:
	StRec _data;

	static bool isNumber(const std::string& s)
	{
		for (auto& ch : s)
			if (!std::isdigit(ch))
				return false;
		return true;
	}
};