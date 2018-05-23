#pragma once

#ifndef HUMAN_H
#define HUMAN_H
#include "Creature.h"
class Human :
	public Creature
{
public:
	Human();
	Human(int s, int h);
	int getDamage();
	virtual string getSpecies();
};
#endif

