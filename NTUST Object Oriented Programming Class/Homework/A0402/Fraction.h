#pragma once
class Fraction
{
public:
	Fraction();
	~Fraction();
private:
	int numerator;
	int denominator;
public:
	void setNumerator(int input_numerator);
	void setDenominator(int input_denominator);
	double getDouble();
	void outputReducedFraction();
};

