#include "Creatures.h"



Creature::Creature() : type(0), strength(10), hitpoints(10)
{
}

Creature::Creature(int newType, int newStrength, int newHit) : type(newType), strength(newStrength), hitpoints(newHit)
{
}

inline void Creature::setType(int new_)
{
	type = new_;
}

inline int Creature::getType()
{
	return type;
}

inline void Creature::setStrength(int new_)
{
	strength = new_;
}

inline int Creature::getStrength()
{
	return strength;
}

inline void Creature::setHitpoints(int new_)
{
	hitpoints = new_;
}

inline int Creature::getHitpoints()
{
	return hitpoints;
}

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
