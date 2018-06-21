#include "Position.h"
#include <cmath>
using namespace std;

Position::Position() :x(0.0), y(0.0), z(0.0)
{
}

Position::Position(double x, double y) : x(x), y(y), z(0.0)
{
}

Position::Position(double x, double y, double z) : x(x), y(y), z(z)
{

}

double Position::operator-(const Position position)
{
	return sqrt(pow((x - position.x), 2) + pow((y - position.y), 2) + pow((z - position.z), 2));
}

double Position::getX()
{
	return x;
}

double Position::getY()
{
	return y;
}

double Position::getZ()
{
	return z;
}
