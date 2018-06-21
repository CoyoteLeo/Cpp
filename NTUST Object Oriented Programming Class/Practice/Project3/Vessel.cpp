#include "Vessel.h"
#include "Shell.h"
#define M_PI 3.14159265358979323846
#include <cmath>
#include <string>
#include <sstream>

Vessel::Vessel(std::string name, double x, double y, double hp, double maxSpeed, double attackRange, double attackCD,
               double defenseRange, double defenseCD, double shellDamage, double shellSpeed)
    : name(name),
      position(x, y),
      hp(hp),
      maxSpeed(maxSpeed),
      speed(0),
      attackRange(attackRange),
      attackCD(attackCD),
      lastAttack(-attackCD),
      defenseRange(defenseRange),
      defenseCD(defenseCD),
      lastDefense(-defenseCD),
      shellDamage(shellDamage),
      shellSpeed(shellSpeed),
      shellCount(0),
      angleInRadian(0)
{
}

void Vessel::move()
{
    double length = speed * 15;
    double x_component = (abs(cos(angleInRadian)) > 0.00000000000001 ?cos(angleInRadian)  : 0);
    double y_component = (abs(sin(-angleInRadian)) > 0.00000000000001 ?sin(-angleInRadian)  : 0);
    position.x += length * x_component;
    position.y += length * y_component;
    if (position.x > 20)
    {
        position.y -= ((position.x - 20) / abs(x_component)) * y_component;
        position.x = 20;
        speed = 0.0;
    }
    else if (position.x < 0)
    {
        position.y -= ((0 - position.x) / abs(x_component)) * y_component;
        position.x = 0;
        speed = 0.0;
    }
    if (position.y > 20)
    {
        position.x -= ((position.y - 20) / abs(y_component)) * x_component;
        position.y = 20;
        speed = 0.0;
    }
    else if (position.y < 0)
    {
        position.x -= ((0 - position.y) / abs(y_component)) * x_component;
        position.y = 0;
        speed = 0.0;
    }
}

Position Vessel::computePosition(long long timeDuration)
{
    double length = speed * timeDuration;
    return Position(position.x + length * cos(angleInRadian), position.y + length * sin(angleInRadian));
}

Shell* Vessel::fire(double x, double y, std::string name){
    return new Shell(position, shellDamage, shellSpeed, name, x, y);
}

bool Vessel::defense(Shell* shell)
{
    return defenseRange >= (position - shell->position);
}

bool Vessel::beFired(Shell* shell)
{
    hp -= shell->damage;
    return hp <= 0;
}

void Vessel::setName(std::string name)
{
    this->name = name;
}

bool Vessel::setMovement(double speed, double angle)
{
    if (abs(speed) > this->maxSpeed)
        return false;
    else
    {
        this->speed = speed;
        this->angleInRadian = angle / 180 * M_PI;
		return true;
    }
}

void Vessel::setLastAttack(long long timestamp)
{
    this->lastAttack = timestamp;
}

Position Vessel::getPosition()
{
    return position;
}
