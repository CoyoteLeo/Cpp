#pragma once
#ifndef POSITION_H
#define POSITION_H


class Position
{
public:
	friend class Vessel;
	friend class GameSystem;
	friend class Shell;
	Position();
	Position(double x, double y);
	Position(double x, double y, double z);
	double operator-(const Position position);
	double getX();
	double getY();
	double getZ();

private:
	double x, y, z;
};
#endif
