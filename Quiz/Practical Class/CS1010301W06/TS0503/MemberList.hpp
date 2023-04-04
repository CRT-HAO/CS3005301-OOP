// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 4, 2023
// Last Update: April 4, 2023
// Problem statement: Student Records

#pragma once

#include <iostream>
#include <vector>

#include "Member.hpp"

class MemberList {
public:
	MemberList() { }

	bool print()
	{
		if (this->_members.size() == 0)
			return false;

		for (auto& mm : this->_members)
			std::cout
			<< mm.getFirstName() << ' '
			<< mm.getLastName() << ' '
			<< mm.getPhone() << std::endl;

		return true;
	}

	bool insert(Member& m)
	{
		if (this->_members.size() >= 10)
			return false;

		for (auto& mm : this->_members)
			if (mm.getFirstName() == m.getFirstName() &&
				mm.getLastName() == m.getLastName() &&
				mm.getPhone() == m.getPhone())
				return false;

		this->_members.push_back(m);

		return true;
	}

	bool remove(size_t index)
	{
		if (index > this->_members.size() - 1)
			return false;

		this->_members.erase(this->_members.begin() + index);

		return true;
	}

	bool search(std::string firstName, std::string lastName, std::string phone,
		size_t& index)
	{
		for (size_t i = 0; i < this->_members.size(); i++)
		{
			Member& mm = this->_members[i];
			if (mm.getFirstName() == firstName &&
				mm.getLastName() == lastName &&
				mm.getPhone() == phone)
			{
				index = i;
				return true;
			}
		}

		return false;
	}

	std::vector<Member> getList()
	{
		return (this->_members);
	}
private:
	std::vector<Member> _members;
};