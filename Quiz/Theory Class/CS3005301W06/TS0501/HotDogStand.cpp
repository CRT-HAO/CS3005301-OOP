// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 28, 2023
// Last Update: March 28, 2023
// Problem statement: Hot dog stand

#include "HotDogStand.h"

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	this->standId = (char*)"";
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id)
{
	this->standId = (char*)id;
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	this->standId = (char*)id;
	this->hotDogSellAmount = amount;
	HotDogStand::totalSellAmount += amount;
}


HotDogStand::~HotDogStand() { }

void HotDogStand::justSold()
{
	this->hotDogSellAmount += 1;
	HotDogStand::totalSellAmount += 1;
}

void HotDogStand::print()
{
	std::cout << this->standId << ' ' << this->hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return (this->hotDogSellAmount);
}

int HotDogStand::allStandSoldAmount()
{
	return (HotDogStand::totalSellAmount);
}
