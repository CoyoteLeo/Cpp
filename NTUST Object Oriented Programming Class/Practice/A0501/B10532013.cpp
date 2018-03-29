#include <iostream>
#include <vector>
using namespace std;

class shape
{
public:
	bool isRectangle;
	double x1, y1, x2, y2, x, y, r;
	int index;
	shape(bool isRectangle_, double x1_, double y1_, double x2_, double y2_, int index_)
	{
		isRectangle = isRectangle_;
		x1 = x1_;
		y1 = y1_;
		x2 = x2_;
		y2 = y2_;
		index = index_;
	}
	shape(bool isRectangle_, double x_, double y_, double r_, int index_)
	{
		isRectangle = isRectangle_;
		x = x_;
		y = y_;
		r = r_;
		index = index_;
	}
};

int main()
{
	int amount;
	while (cin >> amount)
	{
		vector<shape> input;
		char type;
		double x1, y1, x2, y2, x, y, r;
		for (int i = 0; i < amount; i++)
		{
			cin >> type;
			if (type == 'r')
			{
				cin >> x1 >> y1 >> x2 >> y2;
				input.push_back(shape(true, x1, y1, x2, y2, i + 1));
			}
			else
			{
				cin >> x >> y >> r;
				input.push_back(shape(false, x, y, r, i + 1));
			}
		}
		int inputAmount;
		cin >> inputAmount;
		for (int i = 0; i < inputAmount; i++)
		{
			cin >> x >> y;
			bool flag = false;
			for (unsigned int i = 0; i < input.size(); i++)
			{
				if (input[i].isRectangle && x >= input[i].x1 && x <= input[i].x2 && y <= input[i].y1 && y >= input[i].y2)
				{
					cout << "Point (" << x << ", " << y << ") is contained in figure " << input[i].index << endl;
					flag = true;
				}
				else if ((x - input[i].x) * (x - input[i].x) + (y - input[i].y) * (y - input[i].y) <= input[i].r * input[i].r)
				{
					cout << "Point (" << x << ", " << y << ") is contained in figure " << input[i].index << endl;
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "Point (" << x << ", " << y << ") is not contained in any figure" << endl;
			}
		}
	}
	return 0;
}