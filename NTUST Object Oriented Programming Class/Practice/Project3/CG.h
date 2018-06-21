#pragma once
#ifndef CG_H
#define CG_H
#include "Vessel.h"
#include <string>

class CG : public Vessel
{
   public:
    CG(std::string name, double x, double y);
};
#endif