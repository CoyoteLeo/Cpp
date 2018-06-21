#pragma once
#ifndef VESSEL_H
#define VESSEL_H
#include "Position.h"
#include <string>


class Vessel
{
public:
	friend class GameSystem;
	Vessel(std::string name, double x, double y, double hp, double maxSpeed, double attackRange, double attackCD,
		double defenseRange, double defenseCD, double shellDamage, double shellSpeed);
	virtual void move();  // move length between 15 seconds
	virtual Position computePosition(long long timeDuration);
	virtual Shell *fire(double x, double y, std::string name);
	virtual bool defense(Shell *shell); // check it can defense or not
	virtual bool beFired(Shell *shell); // check vessel is destroyed or not
	void setName(std::string name);
	bool setMovement(double speed, double angle);
	void setLastAttack(long long timestamp);
	Position getPosition();

private:
	std::string name;
	double hp;
	double speed;
	double maxSpeed;
	double attackRange;
	int attackCD;
	long long lastAttack;
	double defenseRange;
	int defenseCD;
	long long lastDefense;
	int shellDamage;
	double shellSpeed;
	Position position;
	double angleInRadian;
	int shellCount;
};
#endif