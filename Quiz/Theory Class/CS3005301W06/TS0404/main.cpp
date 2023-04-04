// Name: �i�q�v (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Bank Account

#include <iostream>
#include "BankAccount.h"

using namespace std;

int main() {
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount1.withdraw(100);
	cout << bankAccount1.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount2.save(50);
	cout << bankAccount2.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	return 0;
}