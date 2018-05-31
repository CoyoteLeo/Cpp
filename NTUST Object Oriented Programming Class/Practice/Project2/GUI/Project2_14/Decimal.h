#pragma once
#ifndef DECIMAL_H
#define DECIMAL_H
#include "Number.h"

class Integer;

class Decimal : public Number
{
public:
	Decimal();
	Decimal(std::string input);
	Decimal(Integer integer);
	Decimal(Integer numerator_, Integer denominator_);
	Decimal(const Decimal& obj);  // copy constructor
	Decimal(const char input[]);
	~Decimal();

	virtual void setNumber(std::string num);

	Decimal operator+(Decimal);
	Decimal operator-(Decimal);
	Decimal operator*(Decimal);
	Decimal operator/(Decimal);

	Decimal operator+(Integer);
	Decimal operator-(Integer);
	Decimal operator*(Integer);
	Decimal operator/(Integer);

	Decimal& operator=(Decimal);  // assignment
	Decimal& operator=(Integer);  // assignment

	bool operator>(Decimal);
	bool operator<(Decimal);
	bool operator==(Decimal);
	bool operator>=(Decimal);

	Decimal operator+();
	Decimal operator-();

	Decimal operator^(Decimal);
	Decimal operator^(Integer);
	Decimal factorial();
	Decimal root();
	void fraction_reduction();

	friend std::ostream& operator<<(std::ostream& outputStream, Decimal);
	friend std::istream& operator>>(std::istream& inputStream, Decimal&);
	friend bool isDecimalToInteger(Decimal input);

	Integer getNumerator() const;
	Integer getDenominator() const ;


private:
	Integer * numerator;
	Integer *denominator;
};

bool isDecimal(std::string input);

#endif