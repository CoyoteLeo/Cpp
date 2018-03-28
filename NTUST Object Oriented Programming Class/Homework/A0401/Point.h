#pragma once
class Point
{
public:
	Point();
	~Point();
private:
	float x;
	float y;
public:
	void set(float input1, float input2);
	void move(float length1, float length2);
	void rotate();
	float retrieveVertical();
	float retrieveHorizontal();
};

