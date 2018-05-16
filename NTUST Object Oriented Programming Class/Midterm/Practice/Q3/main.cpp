#include "Starve.h"
#include <iostream>
using namespace std;

int main()
{
	//default settings
	char name[10];
	string command;
	Food meat(20, 10);
	Food vegetable(10, 20);
	Food badMeat(10, -10);
	cout << "Please give your character a name" << endl;
	cin >> name;
	Character player(100, 100, name);
	cout << "Your story starts !" << endl;


	while (getline(cin,command))
	{
	/*
	Advice: Do something here.
	*/
		if (command == "end"||command =="End")
			break;
		player.show();
	
	}

	system("pause");

}