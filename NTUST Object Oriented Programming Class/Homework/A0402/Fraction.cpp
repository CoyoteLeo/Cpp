#include "Fraction.h"
#include<iostream>
using namespace std;


Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}


Fraction::~Fraction()
{
}


void Fraction::setNumerator(int input_numerator)
{
	numerator = input_numerator;
}


void Fraction::setDenominator(int input_denominator)
{
	denominator = input_denominator;
}


double Fraction::getDouble()
{
	return (double)numerator / denominator;
}


void Fraction::outputReducedFraction()
{
	int tempNumerator = numerator, tempDenominator = denominator;
	while (tempNumerator != 0 and tempDenominator != 0)
	{
		if (tempNumerator >= tempDenominator)
		{
			tempNumerator = tempNumerator % tempDenominator;
		}
		else if (tempDenominator > tempNumerator)
		{
			tempDenominator = tempDenominator % tempNumerator;
		}
	}
	if (tempNumerator > tempDenominator)
	{
		cout << numerator / tempNumerator;
		if (denominator / tempNumerator != 1)
		{
			cout << '/' << denominator / tempNumerator;
		}
	}
	else
	{
		cout << numerator / tempDenominator;
		if (denominator / tempDenominator != 1)
		{
			cout << '/' << denominator / tempDenominator;
		}
	}
}
