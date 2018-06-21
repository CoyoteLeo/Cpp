#pragma once
#ifndef TEAM_H
#define TEAM_H
#include <map>
#include <string>
#include <iostream>
#include "Vessel.h"
#include <vector>

class Team
{
public:
	friend class GameSystem;
	void fetchCommand(std::string input);	//cut the whole input command into seperate lines, then put into vector
	std::vector<std::string> commands;
	std::map<std::string, Vessel*> vessels;
	int numOfShells = 0;

private:
	std::string name;
};
#endif