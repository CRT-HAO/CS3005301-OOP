// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 11, 2023
// Last Update: April 11, 2023
// Problem statement: Array to interger

#pragma once

#include <string>

using namespace std;

class Atoi {

private:
	string beTrans;
	static bool IsNumber(const string& str);
	
public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();
};

bool Atoi::IsNumber(const string& str)
{
	return (
		!str.empty() && str.find_first_not_of("-0123456789") == string::npos
	);
}

Atoi::Atoi() { }

Atoi::Atoi(string s) : beTrans(s) { }

void Atoi::SetString(string s) { this->beTrans = s; }

const string Atoi::GetString() { return this->beTrans; }

int Atoi::Length() { return (this->beTrans.length()) -
                     ((this->beTrans[0] == '-') ? 1 : 0); }

bool Atoi::IsDigital() { return Atoi::IsNumber(this->beTrans); }

int Atoi::StringToInteger() { return stoi(this->beTrans); }