#pragma once
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class TerrainReader
{
public:
	TerrainReader(string fileName);
	~TerrainReader();
	//return terrain
	string GetTerrain();
private:
	string terrain;
};

