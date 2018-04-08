#include <iostream>
#include <vector>
#include <string>
#include "monster.h"

using namespace std;

// print menu
void menu();

// main funtion
int main()
{
	int features;
	vector<Monster> monster;
	menu();
	while (cin >> features)
	{
		if (features == 0)
		{
			cout << "Please enter monster state" << endl;
			string name;
			float hp, damage, defense, speed;
			cin >> name >> hp >> damage >> defense >> speed;
			monster.push_back(Monster(name, hp, damage, defense, speed));
		}
		else if (features == 1)
		{
			cout << "Please enter monster name : ";
			string name;
			cin >> name;
			for (unsigned int i = 0; i < monster.size(); i++)
			{
				if (monster[i].GetName() == name)
				{
					monster[i].PrintAllState();
					break;
				}
			}
		}
		else if (features == 2)
		{
			cout << "Please enter monster name : ";
			string name;
			float hp, damage, defense, speed;
			cin >> name;
			for (unsigned int i = 0; i < monster.size(); i++)
			{
				if (monster[i].GetName() == name)
				{
					cin >> name >> hp >> damage >> defense >> speed;
					monster[i].SetName(name);
					monster[i].SetHP(hp);
					monster[i].SetDamage(damage);
					monster[i].SetDefense(defense);
					monster[i].SetSpeed(speed);
				}
			}
		}
		cout << endl;
		menu();
	}
	return 0;
}

// print menu
void menu()
{
	cout << "Create monster enter 0" << endl;
	cout << "Check state enter 1" << endl;
	cout << "Change state enter 2" << endl;
	cout << "Feature : ";
}
