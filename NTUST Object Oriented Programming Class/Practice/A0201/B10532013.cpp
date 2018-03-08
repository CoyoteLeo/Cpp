#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	float point1X, point1Y, point2X, point2Y, point3X, point3Y;
	while (cin >> point1X && cin >> point1Y && cin >> point2X && cin >> point2Y && cin >> point3X && cin >> point3Y)
	{
		float vector1X, vector1Y, vector2X, vector2Y, result;
		vector1X = point2X - point1X;
		vector1Y = point2Y - point1Y;
		vector2X = point3X - point1X;
		vector2Y = point3Y - point1Y;
		result = 0.5 * (vector1X * vector2Y - vector1Y * vector2X);
		if (result < 0)
			cout << fixed << setprecision(2) << result * -1 << endl;
		else
			cout << fixed << setprecision(2) << result << endl;
	}
	return 0;
}