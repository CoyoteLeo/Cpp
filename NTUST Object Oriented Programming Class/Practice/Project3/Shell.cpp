#include "Shell.h"

Shell::Shell(Position position, int damage, double speed, std::string name,double x,double y) :position(position), damage(damage), speed(speed), range(1.5), name(name),target(x,y )
{
}

Shell::Shell(Position position, int damage, double speed, double range, std::string name, double x, double y) : position(position), damage(damage), speed(speed), range(range), name(name), target(x, y )
{
	
}

Position Shell::move(){
	double length = speed*15;
	double angleInRadian = atan(abs(target.y - position.y) / abs(target.x - position.x));
	position.x += (length * cos(angleInRadian)*(target.x > position.x ? 1 : -1));
	position.y += (length * sin(angleInRadian)*(target.y > position.y ? 1 : -1));
	return position;
}

Position Shell::getPosition()
{
	return position;
}
