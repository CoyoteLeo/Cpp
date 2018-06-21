#pragma once
#ifndef FISHER_H
#define FISHER_H
#include "Vessel.h"
#include <string>

class Fisher : public Vessel
{
public:
	Fisher(std::string name, double x, double y);
};
#endif