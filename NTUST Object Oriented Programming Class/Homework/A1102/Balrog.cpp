#include "Balrog.h"



Balrog::Balrog() : Demon()
{
}

Balrog::Balrog(int s, int h) : Demon(2, s, h)
{
}

int Balrog::getDamage()
{
	int damage=Demon::getDamage();
	int damage2 = (rand() % strength) + 1;
	cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}

string Balrog::getSpecies()
{
	return "Balrog";
}