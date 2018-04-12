#include "Rect.h"
#include <string>
#include <iostream>
using namespace std;


Rect::Rect()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

Rect::Rect(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

Rect Rect::operator+(const Rect& a)
{
	int xTemp = (x < a.x ? x : a.x);
	int yTemp = (y > a.y ? y : a.y);
	int w = (x + width > a.x + a.width ? x + width - xTemp : a.x + a.width - xTemp);
	int h = (y - height < a.y - a.height ? yTemp - (y - height) : yTemp - (a.y - a.height));
	return Rect(xTemp, yTemp, w, h);
}

Rect Rect::operator*(const Rect& a)
{
	int xTemp, yTemp, w, h;
	if (x >= a.x && x <= a.x + a.width)
	{
		xTemp = x;
		w = (x + width < a.x + a.width ? x + width - xTemp : a.x + a.width - xTemp);
	}
	else if (a.x >= x && a.x <= x + width)
	{
		xTemp = a.x;
		w = (x + width < a.x + a.width ? x + width - xTemp : a.x + a.width - xTemp);
	}
	else
	{
		cout << "Not overlapping" << endl;
		return Rect();
	}
	if (y <= a.y && y >= a.y - a.height)
	{
		yTemp = y;
		h = (y - height < a.y - a.height ? yTemp - (a.y - a.height) : yTemp - (y - height));
	}
	else if (a.y <= y && a.y >= y - height)
	{
		yTemp = a.y;
		h = (y - height < a.y - a.height ? yTemp - (a.y - a.height) : yTemp - (y - height));
	}
	else
	{
		cout << "Not overlapping" << endl;
		return Rect();
	}
	return Rect(xTemp, yTemp, w, h);
}

string Rect::toString()
{
	string s = "( ";
	s += to_string(x);
	s += " , ";
	s += to_string(y);
	s += " , ";
	s += to_string(width);
	s += " , ";
	s += to_string(height);
	s += " )";
	return s;
}
