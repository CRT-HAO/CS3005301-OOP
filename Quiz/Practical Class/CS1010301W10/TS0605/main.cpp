// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Observation Diary

#include "Diary.h"
#include "Creature.h"

int main() {

	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("0102");
	Creature unknownB("UB", unknownA);
	unknownB["leg"] += 26;
	unknownA.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownA.PrintStatus();
	unknownB.PrintLog();

	Diary::NewDay("0353");
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	unknownA.PrintLog();

}
