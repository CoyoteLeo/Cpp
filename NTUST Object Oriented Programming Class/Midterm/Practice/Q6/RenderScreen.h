#pragma once
#include <iostream>
#include <Windows.h>
#include "PlayerData.h"

class RenderScreen
{
public:
	RenderScreen(string terrain, PlayerData * player);
	~RenderScreen();
	//draw scene
	void RenderFrame();
private:
	string terrain;
	PlayerData * player;
};

