#pragma once
#include <string>
#include<iostream>

using namespace std;

class Number
{
public:
	Number();
	Number(bool type_);
	bool getType();
	~Number();
	virtual void setNumber(string num)=0;
	friend ostream& operator<<(ostream& os,Number *number);

protected:
private:
	bool type;
};
