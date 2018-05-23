#include "Cyberdemon.h"



Cyberdemon::Cyberdemon() : Demon()
{
}

Cyberdemon::Cyberdemon(int s, int h) : Demon(1, s, h)
{
}

int Cyberdemon::getDamage()
{
	return Demon::getDamage();
}

string Cyberdemon::getSpecies()
{
	return "Cyberdemon";
}