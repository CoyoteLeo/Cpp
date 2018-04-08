#include "Robot.h"

Robot::Robot(float x, float y, float power)
{
      this->x = x;
      this->y = y;
      this->power = power < 0 ? 0 : power;
}

float Robot::getX()
{
      return this->x;
}

float Robot::getY()
{
      return this->y;
}

float Robot::getPower()
{
      return this->power;
}

void Robot::move(float x, float y)
{
      float cost = this->moveCost(x, y);
      if (this->power >= cost)
      {
            this->power -= cost;
            this->x += x;
            this->y += y;
      }
      else
      {
            // power is not sufficient
            float distance = cost;
            float canMoveDistance = this->power;
            this->x += x * canMoveDistance / distance;
            this->y += y * canMoveDistance / distance;
            this->power = 0;
      }
}

std::string Robot::speak(char* s)
{
      if (this->power <= 0)
      { 
            return "";
      }

      std::string str(s);
      int i = 0;
      for (; s[i]; ++i)
      {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                  this->power -= 2;
                  str[i] += 32;
            }
            else if (s[i] >= 'a' && s[i] <= 'z')
            {
                  this->power -= 1;
                  str[i] -= 32;
            }
            else
            {
                  this->power -= 0.5;
            }

            if (this->checkPower())
            {
                  return str.substr(0, i);
            }
      }
      return str.substr(0, i + 1);
}

void Robot::charge(float power)
{
      this->power += power;
      this->checkPower();
}

inline float Robot::moveCost(float x, float y)
{
      return sqrt(x * x + y * y);
}

bool Robot::checkPower()
{
      if (this->power < 0)
      {
            this->power = 0;
            return true;
      }
      return false;
}
