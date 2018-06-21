#pragma once
#ifndef CV_H
#define CV_H
#include "Vessel.h"
#include <string>

class CV : public Vessel
{
   public:
    CV(std::string name, double x, double y);
};
#endif