// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Hot dog stand

#pragma once

#include <iostream>

class HotDogStand
{
public:
	HotDogStand();

	// Pre: The variable id is the stand id
	HotDogStand(const char *id);

	// Pre: The variable id is the standid,
	//      amount is start number ofsell amount
	HotDogStand(const char *id, int amount);

	~HotDogStand();

	// Indent: Sold one hot dog from the stand
	void justSold();

	// Indent: Print the id and sales separated by spaces
	void print();

	// Indent: Get sold amount of the stand
	// Post: The function returns the sold amount of the stand
	int thisStandSoldAmount();

	// Indent: Get sold amount of all stands
	// Post: The function returns the sold amount of all stands
	static int allStandSoldAmount();
private:
	char *standId;
	int hotDogSellAmount;
	static int totalSellAmount;
};

