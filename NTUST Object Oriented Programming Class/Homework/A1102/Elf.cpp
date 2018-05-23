#include "Elf.h"



Elf::Elf() : Creature()
{
}

Elf::Elf(int s, int h) : Creature(3, s, h)
{
}

int Elf::getDamage()
{
	int damage = Creature::getDamage();
	if ((rand() % 10) == 0)
	{
		cout << "Magical attack inflicts " << damage <<
			" additional damage points!" << endl;
		damage = damage * 2;
	}
	return damage;
}

string Elf::getSpecies()
{
	return "Elf";
}