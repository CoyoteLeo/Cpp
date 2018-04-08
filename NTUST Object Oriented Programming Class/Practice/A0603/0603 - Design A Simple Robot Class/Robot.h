#pragma once
#include <string>

class Robot
{
public:
      Robot(float x = 0, float y = 0, float power = 100);

      float getX();
      float getY();
      float getPower();

      void move(float x, float y);
      std::string speak(char* s);
      void charge(float power);

private:
      float x;
      float y;
      float power;

      float moveCost(float x, float y);
      // if power is negative, change it to 0 and return true, otherwise return false
      bool checkPower();
};