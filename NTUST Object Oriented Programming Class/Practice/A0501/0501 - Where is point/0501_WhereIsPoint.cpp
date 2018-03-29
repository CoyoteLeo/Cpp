// Name: Zen
// Date: 2018/3/24
// Last Update: 2018/3/24
// Problem statement: Determine if the point is contained in figure.
#include <iostream>
#define MAXFIGNUM 20
using namespace std;

bool contain = false;

struct figure
{
	char kind;
	double x1, x2, y1, y2, r;
};

struct point
{
	double x, y;
};

// Intent: Determine if the point is contained in figure.
// Pre: Point's and figure's information.
// Post: Return the answer.
void containPoint(point p, figure f, int figureID)
{
	if (f.kind == 'r')  // rectangle
	{
		if (p.x >= f.x1 && p.x <= f.x2 && p.y >= f.y2 && p.y <= f.y1)
		{
			cout << "Point (" << p.x << ", " << p.y << ") is contained in figure " << figureID << endl;
			contain = true;
		}
	}
	else  // circle
	{
		double a = (p.x - f.x1), b = (p.y - f.y1);
		if (a * a + b * b <= f.r * f.r)
		{
			cout << "Point (" << p.x << ", " << p.y << ") is contained in figure " << figureID << endl;
			contain = true;
		}
	}
}

int main(void)
{
	int figureNum, pointNum;
	char inputFig;
	figure fig[MAXFIGNUM];
	point p[MAXFIGNUM];

	while (cin >> figureNum)
	{
		for (int i = 0; i < figureNum; i++)  // Input figure's information
		{
			cin >> inputFig;
			if (inputFig == 'r')
			{
				cin >> fig[i].x1 >> fig[i].y1 >> fig[i].x2 >> fig[i].y2;
			}
			else if (inputFig == 'c')
			{
				cin >> fig[i].x1 >> fig[i].y1 >> fig[i].r;
			}
			fig[i].kind = inputFig;
		}

		cin >> pointNum;

		for (int i = 0; i < pointNum; i++)  // Input point's information
			cin >> p[i].x >> p[i].y;

		for (int i = 0; i < pointNum; i++)  // Output the result
		{
			contain = false;

			for (int j = 0; j < figureNum; j++)
				containPoint(p[i], fig[j], (j + 1));  // Determine if the point is contained in figure

			if (!contain)
				cout << "Point (" << p[i].x << ", " << p[i].y << ") is not contained in any figure" << endl;
		}
	}

	system("pause");
	return 0;
}