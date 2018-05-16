#include "Creature.h"
#include "Diary.h"

int main() {

	// Test data 1

	Diary::NewDay("-2000");

	Diary::NewDay("-1050");
	Creature horse("Hourse");
	horse["leg"] = 2;
	horse["hand"] = 2;

	Diary::NewDay("-1000");
	horse["leg"] += 1;
	horse["hand"] -= 1;

	Diary::NewDay("-950");
	horse["leg"] += 1;
	horse["hand"] -= 1;

	Diary::NewDay("-950");
	horse["hand"] = 0;
	Creature horse2("Hourse2", horse);
	horse2.PrintLog();

	Diary::NewDay("1000");
	horse2.PrintStatus();
	horse["horn"] += 1;

	Diary::NewDay("1220");
	horse2["wing"] -= -2;
	horse.PrintLog();
	horse.PrintStatus();

	Diary::NewDay("4320");
	horse2.PrintLog();
	horse2.PrintStatus();

	Diary::NewDay("5500");

	system("pause");
	return 0;
}