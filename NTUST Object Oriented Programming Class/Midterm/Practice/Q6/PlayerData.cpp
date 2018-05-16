#include "PlayerData.h"

PlayerData::PlayerData(string name, float hp)
{
	this->name = name;
	this->hp = hp;
	this->pos = 0;
	this->face = 1;
}

PlayerData::~PlayerData()
{
}


void PlayerData::SetName(string name)
{
	this->name = name;
}

string PlayerData::GetName()
{
	return name;
}

void PlayerData::SetHp(float hp)
{
	this->hp = hp;
}

float PlayerData::GetHp()
{
	return hp;
}


void PlayerData::SetPos(int pos)
{
	this->pos = pos;
}

int PlayerData::GetPos()
{
	return pos;
}

void PlayerData::SetFace(int face)
{
	this->face = face;
}

int PlayerData::Getface()
{
	return face;
}
