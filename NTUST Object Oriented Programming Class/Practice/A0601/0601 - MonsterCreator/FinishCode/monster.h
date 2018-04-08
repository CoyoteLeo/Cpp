#pragma once
#include <iostream> 
#include <string>

using namespace std;

class Monster
{
public:
	Monster();
	Monster(string name, float hp, float damage, float defense, float speed);
	void SetName(string name);
	void SetHP(float hp);
	void SetDamage(float damage);
	void SetDefense(float defence);
	void SetSpeed(float speed);

	void PrintAllState();
	string GetName();
	float GetHP();
	float GetDamage();
	float GetDefence();
	float GetSpeed();

	~Monster();
private:
	string name;
	float hp;
	float damage;
	float defense;
	float speed;
};

