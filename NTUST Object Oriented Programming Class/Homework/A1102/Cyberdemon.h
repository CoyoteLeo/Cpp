#pragma once
#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "Demon.h"
class Cyberdemon :
	public Demon
{
public:
	Cyberdemon();
	Cyberdemon(int s, int h);
	int getDamage();
	virtual string getSpecies();
};
#endif

