#include "Human.h"



Human::Human() : Creature()
{
}

Human::Human(int s, int h) : Creature(0, s, h)
{
}

int Human::getDamage()
{
	return Creature::getDamage();
}

string Human::getSpecies()
{
	return "Human";
}
