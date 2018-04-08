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

Monster::Monster()
{
}

Monster::Monster(string name, float hp, float damage, float defense, float speed)
{
    this->name = name;
    this->hp = hp;
    this->damage = damage;
    this->defense = defense;
    this->speed = speed;
}

void Monster::SetName(string name)
{
    this->name = name;
}

void Monster::SetHP(float hp)
{
    this->hp = hp;
}

void Monster::SetDamage(float damage)
{
    this->damage = damage;
}

void Monster::SetDefense(float defence)
{
    this->defense = defence;
}

void Monster::SetSpeed(float speed)
{
    this->speed = speed;
}

void Monster::PrintAllState()
{
    cout << "Name : " << name << endl;
    cout << "Hp : " << hp << endl;
    cout << "Damage : " << damage << endl;
    cout << "Defence : " << defense << endl;
    cout << "Speed : " << speed << endl;
}

string Monster::GetName()
{
    return name;
}

float Monster::GetHP()
{
    return hp;
}

float Monster::GetDamage()
{
    return damage;
}

float Monster::GetDefence()
{
    return defense;
}

float Monster::GetSpeed()
{
    return speed;
}

Monster::~Monster()
{
}
