#pragma once
#include <string>
using namespace std;

class Rect
{
private:
	int x, y, width, height;

public:
	Rect();
	Rect(int x, int y, int width, int height);
	Rect operator+(const Rect& a);
	Rect operator*(const Rect& a);
	string toString();
};

