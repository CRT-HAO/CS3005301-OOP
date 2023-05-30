// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 31, 2023
// Last Update: May 31, 2023
// Problem statement: ATM

#pragma once

#include <iostream>

class InsufficientFunds : public std::exception
{
public:
    InsufficientFunds() {}
};

class NegativeDeposit : public std::exception
{
public:
    NegativeDeposit() {}
};

class Account
{
private:
    double balance;

public:
    Account() { balance = 0; }
    Account(double initialDeposit) { balance = initialDeposit; }
    double getBalance() { return balance; }

    // returns new balance or -1 if error
    double deposit(double amount)
    {
        if ( amount > 0 )
            balance += amount;
        else
            throw NegativeDeposit();
        return balance;
    }

    // return new balance or -1 if invalid amount
    double withdraw(double amount)
    {
        if ( (amount > balance) || (amount < 0) )
            throw InsufficientFunds();
        else
            balance -= amount;
        return balance;
    }
};
