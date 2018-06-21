#pragma once
#ifndef SHELL_H
#define SHELL_H
#include "Position.h"
#include <string>
#include<vector>

class Shell
{
public:
	friend class Vessel;
	friend class GameSystem;
	Shell(Position position, int damage, double speed, std::string name, double x, double y);
	Shell(Position position, int damage, double speed, double range, std::string name, double x, double y);
	virtual Position move();
	long long explosionTime;
	Position getPosition();

private:
	std::string name;  // shell_(team+id), id為發射順序
	Position position;
	Position target;
	int damage;
	double range;
	double speed;
	std::vector<std::string> hitRecord;
};
#endif