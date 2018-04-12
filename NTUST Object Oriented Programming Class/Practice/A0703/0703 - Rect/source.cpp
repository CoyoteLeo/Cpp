// Name: TA
// Date: April 4th, 2018
// Last Update: April 4th, 2018
// Problem statement: This C++ program implements Vector class.
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Rect
{
public:
	Rect();
	Rect(int _x, int _y, int _width, int _height);
	friend Rect operator+(const Rect&, const Rect&);
	friend Rect operator*(const Rect&, const Rect&);
	string toString();

private:
	int x;
	int y;
	int width;
	int height;
};

//Default constructor
Rect::Rect() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

//constructor
Rect::Rect(int _x, int _y, int _width, int _height) {
	x = _x;
	y = _y;
	width = _width;
	height = _height;
}

//union
Rect operator+(const Rect& r1, const Rect& r2)
{
	int left, right, top, bottom;

	//left
	left = min(r1.x, r2.x);

	//right
	right = max(r1.x + r1.width, r2.x + r2.width);

	//top
	top = max(r1.y, r2.y);
	
	//bottom
	bottom = min(r1.y - r1.height, r2.y - r2.height);

	return Rect(left, top, right - left, top - bottom);
}

//Intersection
Rect operator*(const Rect& r1, const Rect& r2)
{
	bool xOverlap = (r1.x >= r2.x && r1.x <= r2.x + r2.width) || (r2.x >= r1.x && r2.x <= r1.x + r1.width);
	bool yOverlap = (r1.y >= r2.y - r2.height && r1.y <= r2.y) || (r2.y >= r1.y - r1.height && r2.y <= r1.y);
	
	if (xOverlap && yOverlap) {
		
		int left, right, top, bottom;

		if (r1.x >= r2.x && r1.x <= r2.x + r2.width) {
			left = r1.x;
			right = min(r1.x + r1.width, r2.x + r2.width);
		}
		else {
			left = r2.x;
			right = min(r1.x + r1.width, r2.x + r2.width);
		}

		if (r1.y >= r2.y - r2.height && r1.y <= r2.y) {
			top = r1.y;
			bottom = max(r1.y - r1.height, r2.y - r2.height);
		}
		else {
			top = r2.y;
			bottom = max(r1.y - r1.height, r2.y - r2.height);
		}

		return Rect(left, top, right - left, top - bottom);
	}
	else {
		cout << "Not overlapping" << endl;
		return Rect();
	}
}

string Rect::toString() {
	string info = "";

	info = "( " + to_string(this->x) + " , " + to_string(this->y) + " , " + to_string(this->width) + " , " + to_string(this->height) + " ) ";

	return info;
}

int main()
{
	int x1, y1, width1, height1;	//for rect1
	int x2, y2, width2, height2;	//for rect2

	while (cin >> x1 >> y1 >> width1 >> height1 
		>> x2 >> y2 >> width2 >> height2) {

		Rect rect1 = Rect(x1, y1, width1, height1);
		Rect rect2 = Rect(x2, y2, width2, height2);
		Rect unionRect = rect1 + rect2;
		
		cout << "union : " << unionRect.toString() << endl;

		Rect interRect = rect1 * rect2;
		cout << "intersection : " << interRect.toString() << endl;
	}
	system("pause");
	return 0;
}

