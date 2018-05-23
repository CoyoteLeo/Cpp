#include "Demon.h"

Demon::Demon() : Creature()
{
}

Demon::Demon(int t,int s, int h) : Creature(t, s, h)
{
}

int Demon::getDamage()
{

	int damage = Creature::getDamage();
	if ((rand() % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "
			<< " additional damage points!" << endl;
	}
	return damage;
}
