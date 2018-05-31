#include "Number.h"
#include "Integer.h"
#include "Decimal.h"

Number::Number()
{
}

Number::Number(bool type_) :type(type_)
{
}

bool Number::getType()
{
	return type;
}

Number::~Number()
{
}

ostream & operator<<(ostream & os, Number * number)
{
	if (number->type)
		os << *(Integer*)number;
	else
		os << *(Decimal*)number;
	return os;
}
