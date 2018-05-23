#pragma once

#ifndef ELF_H
#define ELF_H
#include "Creature.h"
class Elf :
	public Creature
{
public:
	Elf();
	Elf(int s, int h);
	int getDamage();
	virtual string getSpecies();
};
#endif
