#include "RenderScreen.h"

RenderScreen::RenderScreen(string terrain, PlayerData * player)
{
	this->terrain = terrain;
	this->player = player;
}

RenderScreen::~RenderScreen()
{
}

void RenderScreen::RenderFrame()
{
	//print game screen

	//redraw game scene
	Sleep(50);
	system("cls");

	/*
		print player state
		Name:
		HP:
		X:
	*/

	/*
		print game scene 
		width = 20
		heigh = 10
	*/

}