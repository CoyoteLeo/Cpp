#include "Creature.h"
#include "Diary.h"

int main() {

	// Test data 2

	Diary::NewDay("0-0");

	Diary::NewDay("0-1");
	Creature earthWorm("Worm");

	Diary::NewDay("0-2");
	Creature snake("Snake", earthWorm);
	snake.PrintStatus();

	Diary::NewDay("1-1");
	earthWorm["tail"] = 2;
	snake["tail"] = 1;
	snake["head"] = 1;
	snake.PrintLog();

	Diary::NewDay("1-2");
	Creature snake2("Multi-headed", snake);
	snake2["head"] += 7;
	snake2["tail"] -= -7;
	earthWorm["tail"] -= 1;

	Diary::NewDay("1-3");
	earthWorm["tail"] += -1;

	Diary::NewDay("1-4");
	earthWorm["tail"] = 0;

	Diary::NewDay("2-1");
	earthWorm.PrintLog();
	earthWorm.PrintStatus();
	snake2.PrintLog();
	snake2.PrintStatus();

	Diary::NewDay("???-1");
	snake["hammer?"] = 1;
	snake.PrintLog();
	snake.PrintStatus();

	system("pause");
	return 0;
}