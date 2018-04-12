#include "Vector.h"



Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector Vector::operator+(const Vector& a)
{
	return Vector(x + a.x, y + a.y);
}

Vector Vector::operator-(const Vector& a)
{
	return Vector(x - a.x, y - a.y);
}

float Vector::operator*(const Vector& a)
{
	return x * a.x + y * a.y;
}

Vector Vector::operator*(const float& f)
{
	return Vector(x * f, y * f);
}
