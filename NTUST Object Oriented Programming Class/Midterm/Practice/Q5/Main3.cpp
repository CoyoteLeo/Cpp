#include "Creature.h"
#include "Diary.h"

int main() {

	// Test data 3

	Diary::NewDay("A01");
	Diary::NewDay("B01");

	Diary::NewDay("C01");
	Creature fish("Fish");
	fish.PrintLog();
	fish["head"] = 1;
	fish["fin"] += 7;

	Diary::NewDay("C02");
	Creature clone01("FishC1", fish);
	Creature clone02("FishC2", fish);
	Creature clone03("FishC3", fish);
	Creature clone04("FishC4", fish);
	Creature clone05("FishC5", fish);
	fish.PrintLog();

	Diary::NewDay("C03");
	Diary::NewDay("C04");
	clone02["fin"] += 1;

	Diary::NewDay("C05");
	Diary::NewDay("C06");
	Diary::NewDay("C07");
	clone03["fin"] += -3;

	Diary::NewDay("C08");
	clone03["fin"] += 0;

	Diary::NewDay("C76");
	clone03["hand"] += 1;
	clone01.PrintStatus();
	clone02.PrintStatus();
	clone03.PrintStatus();
	clone04.PrintStatus();
	clone05.PrintStatus();

	Diary::NewDay("D01");
	Creature clone11("FishD1", clone03);
	Creature clone12("FishD2", clone03);
	Creature clone13("FishD3", clone03);

	Diary::NewDay("D05");
	clone13["fin"] -= 3;

	Diary::NewDay("D08");
	clone11["fin"] -= 1;

	Diary::NewDay("D18");
	clone11["fin"] -= 2;

	Diary::NewDay("D30");
	clone13["hand"] += 1;
	clone11.PrintStatus();
	clone12.PrintStatus();
	clone13.PrintStatus();

	Diary::NewDay("E01");
	Creature mermaid("Mermaid", clone13);
	clone13["fin"] -= 1;
	clone03.PrintLog();
	clone03.PrintStatus();
	clone13.PrintLog();
	clone13.PrintStatus();
	mermaid.PrintLog();
	mermaid.PrintStatus();

	Diary::NewDay("E04");

	system("pause");
	return 0;
}