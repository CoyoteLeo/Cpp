#pragma once
#ifndef System_H
#define System_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Vessel.h"
#include "Terrain.h"
#include "Shell.h"
#include "Team.h"
#include "BB.h"
#include "CG.h"
#include "CV.h"
#include "DD.h"
#include "Fisher.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<algorithm>
#include <math.h>

class GameSystem{
public:
	GameSystem();
	Team teamA;
	Team teamB;
	std::vector<std::string> logs;
	std::map<std::string, Shell*> shells;  //場面上的砲彈
	std::vector<Terrain> terrain;
	void pause();
	void start();
	void updateFrame();
	bool running;
	long long timer;  //要做暫停, 只能在暫停時輸入, 現實中的1秒 = 遊戲中的15秒


private:
	void cleanBrokenVessel(long long timestamp, Position position);
	void executeCommand(Team& team);
};
#endif