// Name: TKG
// Date: March 1st, 2018
// Last Update: March 8th, 2018
// Problem statement: This C++ program computes the area of an arbitrary triangle.
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

float GetArea(float x1, float y1, float x2, float y2, float x3, float y3);
float GetArea2(float x1, float y1, float x2, float y2, float x3, float y3);
float GetDistance(float x1, float y1, float x2, float y2);

int main()
{
	vector<float> buffer;
	float input;
	cout << setprecision(2) << fixed;
	while (cin >> input)
	{
		buffer.push_back(input);
		if (buffer.size() == 6)
		{
			// Compute the area of a triangle with given points.
			cout << GetArea(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]) << endl;
			buffer.clear();
		}
	}

	return 0;
}
// Intent: Compute the area of a triangle with given points.
// Pre: Must pass three coordinates of the points (float).
// Post: The function return the area of the triangle.
float GetArea(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return fabsf(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0);
}
// Another approach
// Intent: Compute the area of a triangle with given points.
// Pre: Must pass three coordinates of the points (float).
// Post: The function return the area of the triangle.
float GetArea2(float x1, float y1, float x2, float y2, float x3, float y3)
{
	float a = GetDistance(x1, y1, x2, y2);
	float b = GetDistance(x1, y1, x3, y3);
	float c = GetDistance(x3, y3, x2, y2);
	float s = (a + b + c) / 2.0;
	return sqrtf(s * (s - a) * (s - b) * (s - c));
}
// Intent: Compute the euclidean distance between two points.
// Pre: Must pass two coordinates of the points (float).
// Post: The function return the euclidean distance.
float GetDistance(float x1, float y1, float x2, float y2)
{
	return sqrtf(powf((x1 - x2), 2.0) + powf((y1 - y2), 2.0));
}