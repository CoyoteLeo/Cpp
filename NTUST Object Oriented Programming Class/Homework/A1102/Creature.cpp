#include "Creatures.h"



Creature::Creature() : type(0), strength(10), hitpoints(10)
{
}

Creature::Creature(int newType, int newStrength, int newHit) : type(newType), strength(newStrength), hitpoints(newHit)
{
}

void Creature::setType(int new_)
{
	type = new_;
}

int Creature::getType()
{
	return type;
}

void Creature::setStrength(int new_)
{
	strength = new_;
}

int Creature::getStrength()
{
	return strength;
}

inline void Creature::setHitpoints(int new_)
{
	hitpoints = new_;
}

int Creature::getHitpoints()
{
	return hitpoints;
}

int Creature::getDamage()
{
	int damage;
	// All creatures inflict damage which is a 
	// random number up to their strength 
	damage = (rand() % strength) + 1;
	cout << getSpecies() << " attacks for " <<damage << " points!" << endl;
	return damage;
}

/*
string Creature::getSpecies()
{
	switch (type)
	{
	case 0:
		return "Human";
	case 1:
		return "Cyberdemon";
	case 2:
		return "Balrog";
	case 3:
		return "Elf";
	}
	return "Unknown";
}
*/