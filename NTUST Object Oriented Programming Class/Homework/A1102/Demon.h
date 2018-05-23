#pragma once

#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"
class Demon :
	public Creature
{
public:
	Demon();
	Demon(int t, int s, int h);
	int getDamage();
};
#endif
