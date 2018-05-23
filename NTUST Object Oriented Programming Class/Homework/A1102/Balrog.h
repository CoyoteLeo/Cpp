#pragma once

#ifndef BALROG_H
#define BALROG_H
#include "Demon.h"
class Balrog :
	public Demon
{
public:
	Balrog();
	Balrog(int s, int h);
	int getDamage();
	virtual string getSpecies();
};
#endif
