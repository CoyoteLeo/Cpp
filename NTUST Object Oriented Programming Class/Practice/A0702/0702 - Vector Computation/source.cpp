// Name: TA
// Date: April 4th, 2018
// Last Update: April 4th, 2018
// Problem statement: This C++ program implements Vector class.
#include <iostream>
using namespace std;

class Vector
{
public:
	float x;
	float y;
	Vector();
	Vector(float _x, float _y);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	float operator*(const Vector&);
	Vector operator*(const float&);
};

//Default constructor
Vector::Vector() {
	x = 0.0f;
	y = 0.0f;
}

//constructor
Vector::Vector(float _x, float _y) {
	x = _x;
	y = _y;
}

//add two vectors together
Vector Vector::operator+(const Vector& _v)
{
	Vector v;
	v.x = x + _v.x;
	v.y = y + _v.y;

	return v;
}

//substract operator
Vector Vector::operator-(const Vector& _v)
{
	Vector v;
	v.x = x - _v.x;
	v.y = y - _v.y;

	return v;
}

//dot two vector
float Vector::operator*(const Vector& _v)
{
	return x * _v.x + y * _v.y;
}

//scale the vector
Vector Vector::operator*(const float& _v)
{
	return Vector(_v * x, _v * y);
}

int main()
{
	float x, y, k;
	while (cin >> x >> y) {
		Vector mainVector = Vector(x, y);
		
		cin >> x >> y;
		Vector addVector = Vector(x, y);
		Vector addResult = mainVector + addVector;

		cin >> x >> y;
		Vector subVector = Vector(x, y);
		Vector subResult = mainVector - subVector;

		cin >> x >> y;
		Vector dotVector = Vector(x, y);
		float dotResult = mainVector * dotVector;

		cin >> k;
		Vector scaleVector = mainVector * k;

		cout << "Add Result = ( " << addResult.x << " , " << addResult.y << " )"<< endl;
		cout << "Subtract Result = ( " << subResult.x << " , " << subResult.y << " )" << endl;
		cout << "Dot Result = " << dotResult << endl;
		cout << "Scale Result = ( " << scaleVector.x << " , " << scaleVector.y << " )" << endl;
	}

	system("pause");
	return 0;
}