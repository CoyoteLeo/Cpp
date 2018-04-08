#include <iostream> 
#include <vector>
#include "monster.h"

using namespace std;

// print menu
void menu();

// main funtion
int main() {
	int features;
	int monsterCount = 0;
	//會用map的人用map比較好
	vector<Monster> monster;

	menu();
	while (cin >> features)
	{
		string name;
		float  hp, damage, defense, speed;
		if (features == 0)
		{
			cout << "Please enter monster state" << endl;
			cin >> name >> hp >> damage >> defense >> speed;

			Monster tempMonster(name, hp, damage, defense, speed);
			monster.push_back(tempMonster);
			monsterCount++;
		}
		else if (features == 1)
		{
			cout << "Please enter monster name : ";
			cin >> name;
			for (int i = 0; i < monster.size(); i++)
			{
				if (monster[i].GetName().compare(name) == 0)
				{
					monster[i].PrintAllState();
				}
			}
		}
		else if (features == 2)
		{
			cout << "Please enter monster name : ";
			cin >> name;
			for (int i = 0; i < monsterCount; i++)
			{
				if (monster[i].GetName().compare(name) == 0)
				{
					cout << "Please enter new state : ";
					cin >> name >> hp >> damage >> defense >> speed;
					monster[i].SetName(name);
					monster[i].SetHP(hp);
					monster[i].SetDamage(damage);
					monster[i].SetDefense(defense);
					monster[i].SetSpeed(speed);
					break;
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
