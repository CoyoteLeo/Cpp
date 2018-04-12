#pragma once
class Vector
{
public:
	float x, y;
	Vector(float x, float y);
	Vector operator+(const Vector& a);
	Vector operator-(const Vector& a);
	float operator*(const Vector& a);
	Vector operator*(const float& a);
};

