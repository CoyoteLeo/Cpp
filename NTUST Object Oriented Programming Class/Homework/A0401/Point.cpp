#include "Point.h"



Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}


Point::~Point()
{
}


void Point::set(float input1, float input2)
{
	x = input1;
	y = input2;
}


void Point::move(float length1, float length2)
{
	x += length1;
	y += length2;
}


void Point::rotate()
{
	float yInitial = y;
	y = -x;
	x = yInitial;
}


float Point::retrieveVertical()
{
	return x;
}


float Point::retrieveHorizontal()
{
	return y;
}
