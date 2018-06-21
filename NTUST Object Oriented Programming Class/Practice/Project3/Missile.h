#pragma once
#ifndef Missile_H
#define Missile_H
#include <string>
#include "Shell.h"
#include "Vessel.h"


class Missile : public Shell
{
   public:
    Position move(){};

   private:
    Vessel target;
};
#endif