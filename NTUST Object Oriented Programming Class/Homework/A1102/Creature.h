#pragma once

#ifndef CREATURES_H
#define CREATURES_H
#include <string>
#include <iostream>
using namespace std;

class Creature
{
protected:
	int type;             // 0 human, 1 cyberdemon, 2 balrog, 3 elf
	int strength;         // How much damage we can inflict
	int hitpoints;        // How much damage we can sustain
	virtual string getSpecies()=0;  // Returns type of species
public:
	Creature();  // Initialize to human, 10 strength, 10 hit points
	Creature(int newType, int newStrength, int newHit);
	// Initialize creature to new type, strength, hit points
	// Also add appropriate accessor and mutator functions for type, strength, and hit points
	void setType(int new_);
	int getType();
	void setStrength(int new_);
	int getStrength();
	void setHitpoints(int new_);
	int getHitpoints();
	int getDamage();
};
#endif
