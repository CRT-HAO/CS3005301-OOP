// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 4, 2023
// Last Update: April 4, 2023
// Problem statement: Student Records

#include <iostream>

#include "Member.hpp"
#include "MemberList.hpp"

using namespace std;

MemberList gList;

// Indent: Check Input Member Data Valid
// Pre: The variables firstName, lastName and phone are string type
// Post: The function returns if the data valid
bool checkInputValid(string firstName, string lastName, string phone)
{
	return (
		Member::isFirstNameValid(firstName) &&
		Member::isLastNameValid(lastName) &&
		Member::isPhoneValid(phone)
		);
}

int main()
{
	for (string command;(cin >> command) && !cin.eof();)
	{
		if (command == "print")
		{
			bool success = gList.print();
			if (!success)
			{
				cout << "Print Error" << endl;
				continue;
			}
		}
		else if (command == "insert")
		{
			string firstName, lastName, phone;
			cin >> firstName >> lastName >> phone;

			bool inputValid = checkInputValid(firstName, lastName, phone);
			if (!inputValid)
			{
				cout << "Input Error" << endl;
				continue;
			}

			Member m;
			bool setSuccess = m.setFirstName(firstName) &&
				m.setLastName(lastName) && m.setPhone(phone);
			if (!setSuccess)
			{
				cout << "Set Member Error" << endl;
				continue;
			}

			bool insertSuccess = gList.insert(m);
			if (!insertSuccess)
			{
				cout << "Insert Error" << endl;
				continue;
			}
		}
		else if (command == "delete")
		{
			string firstName, lastName, phone;
			cin >> firstName >> lastName >> phone;

			bool inputValid = checkInputValid(firstName, lastName, phone);
			if (!inputValid)
			{
				cout << "Input Error" << endl;
				continue;
			}

			size_t index = 0;
			bool searchSuccess = gList.search(firstName, lastName, phone,
				index);
			if (!searchSuccess)
			{
				cout << "Delete Error" << endl;
				continue;
			}

			bool delSuccess = gList.remove(index);
			if (!delSuccess)
			{
				cout << "Delete Error" << endl;
				continue;
			}
		}
		else if (command == "search")
		{
			string firstName, lastName, phone;
			cin >> firstName >> lastName >> phone;

			bool inputValid = checkInputValid(firstName, lastName, phone);
			if (!inputValid)
			{
				cout << "Input Error" << endl;
				continue;
			}

			size_t index = 0;
			bool searchSuccess = gList.search(firstName, lastName, phone,
				index);
			if (!searchSuccess)
			{
				cout << "Search Error" << endl;
				continue;
			}

			cout << index << endl;
		}
	}

	return 0;
}