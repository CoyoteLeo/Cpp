#pragma once
#include <string>

using namespace std;

class PlayerData
{
public:
	PlayerData(string name, float hp);
	~PlayerData();

	//get, set name
	void SetName(string name);
	string GetName();

	//get, set hp
	void SetHp(float hp);
	float GetHp();

	//get, set pos
	void SetPos(int pos);
	int GetPos();

	//get, set face
	void SetFace(int face);
	int Getface();

private:
	//player's name
	string name;
	//player's hp
	float hp;
	//player's x coordinate position
	int pos;
	//face which side: 1 is right, -1 is left.
	int face;
};

