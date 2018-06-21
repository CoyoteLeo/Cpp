#pragma once
#ifndef BB_H
#define BB_H
#include "Vessel.h"
#include <string>

class BB : public Vessel
{
   public:
    BB(std::string name, double x, double y);
};
#endif