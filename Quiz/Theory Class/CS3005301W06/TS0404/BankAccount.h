// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Bank Account

#pragma once

#include <iostream>

class BankAccount {
private:
	int balance;
	static int total;
public:

	BankAccount();
	
	// Pre: The variable input is pre saved money
	BankAccount(int input);

	// Indent: Withdraw money from account
	// Pre: The variable output is money to withdraw
	void withdraw(int output);

	// Indent: Save money to account
	// Pre: The variable input is money to save
	void save(int input);

	// Indent: Get balance money from account
	// Post: The function returns the balance from account
	int getBalance();

	// Indent: Get all money from bank
	// Post: The function returns the all money from bank
	static int getAllMoneyInBank();
};