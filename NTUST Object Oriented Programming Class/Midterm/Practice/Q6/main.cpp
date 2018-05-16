#include <iostream>
#include "conio.h"
#include "TerrainReader.h"
#include "PlayerData.h"
#include "RenderScreen.h"

using namespace std;

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

int main()
{
	//read terrain
	TerrainReader *terrainReader = new TerrainReader("Terrain.txt");
	//create!
	string terrain = terrainReader->GetTerrain();

	PlayerData *player = new PlayerData("Jenny", 1);
	RenderScreen *renderscreen = new RenderScreen(terrain, player);

	while (true)
	{
		//if user press some thing
		if (_kbhit())
		{
			//get key input
			char input = _getch();
			
			if (input == KEY_RIGHT)		//user press right
			{
				/*
					do somthing
				*/
			}
			else if (input == KEY_LEFT)	//user press left
			{
				/*
				do somthing
				*/
			}
			else if (input == KEY_ESC)	//end game
			{
				break;
			}
		}

		//redraw screen. like FPS (X
		renderscreen->RenderFrame();
	}
	return 0;
}