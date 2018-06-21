#pragma once
#ifndef DD_H
#define DD_H
#include "Vessel.h"
#include <string>

class DD : public Vessel
{
   public:
    DD(std::string name, double x, double y);
};
#endif