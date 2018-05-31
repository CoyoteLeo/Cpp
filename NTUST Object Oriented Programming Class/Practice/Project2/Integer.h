#pragma once
#ifndef INTEGER_H
#define INTEGER_H
#include "Number.h"
#include <string>
#include<iostream>
#include<vector>
using namespace std;

class Decimal;

class Integer : public Number
{
	//friend class Decimal;
public:
	Integer();
	Integer(string input);
	Integer(bool sign_, vector<int> numArray_);
	Integer(int);
	Integer(const Integer& obj); // copy constructor
	Integer(const Decimal &obj); //copy constructor
	Integer(const char input[]);  // assignment
	~Integer();

	virtual void setNumber(string num);

	Integer operator+(Integer); 
	Integer operator-(Integer);
	Integer operator*(Integer);
	Integer operator/(Integer);

	Decimal operator+(Decimal);
	Decimal operator-(Decimal);
	Decimal operator*(Decimal);
	Decimal operator/(Decimal);

	Integer& operator=(const Integer&);  // assignment
	Integer& operator=(const Decimal&);  // assignment
	

	Integer operator+();
	Integer operator-();

	bool operator>(Integer);
	bool operator<(Integer);
	bool operator==(Integer);
	bool operator<=(Integer);
	bool operator>=(Integer);
	bool operator!=(Integer);


	Integer operator^(Integer);
	Decimal operator^(Decimal);
	Integer factorial();
	Decimal root();
	friend Integer gcd(Integer m, Integer n);

	friend std::ostream& operator<<(std::ostream& outputStream, Integer);  //��X
	friend std::istream& operator>>(std::istream& inputStream, Integer&);  //��J

	void popZero();

	vector<int>getNumArray();
	void setNumArray(vector<int>);
	void minusOneLastDigit();
	bool getSign();
	void setSign(bool sign_);

private:
	bool sign;             //紀錄正負號 0負1正
	vector<int> numArray;  //紀錄實數
};

bool isInteger(string input);

#endif