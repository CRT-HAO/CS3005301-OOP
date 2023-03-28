// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Bank Account

#include "BankAccount.h"

int BankAccount::total = 0;

BankAccount::BankAccount()
{
	this->balance = 0;
}

BankAccount::BankAccount(int input)
{
	this->balance = 0;
	this->save(input);
}

void BankAccount::withdraw(int output)
{
	this->balance -= output;
	BankAccount::total -= output;
}

void BankAccount::save(int input)
{
	this->balance += input;
	BankAccount::total += input;
}

int BankAccount::getBalance()
{
	return (this->balance);
}

int BankAccount::getAllMoneyInBank()
{
	return (BankAccount::total);
}