// Name: ZEN
// Date: March 4th, 2018
// Last Update: March 9th, 2018
// Problem statement: Find the edge of the polygon.
#include <iostream>
#define MAX_NUM 1000
using namespace std;

int main(void)
{
	int height[MAX_NUM + 1];
	memset(height, 0, sizeof(int) * (MAX_NUM + 1));

	int xLeft, xRight, y, bound = 0;
	int currentHeight = 0;
	
	while (cin >> xLeft >> y >> xRight)
	{
		if (xRight > bound)  // 記錄 x 的最右邊界
			bound = xRight;

		for (int i = xLeft; i < xRight; i++)  // 記錄每個 x 的最高點
			if (y > height[i])
				height[i] = y;
	}

	for (int i = 0; i < bound; i++)
	{
		if (height[i] != currentHeight)  // 尋找和目前高度不同的 x
		{
			cout << i << " " << currentHeight << " ";
			cout << i << " " << height[i] << " ";
			currentHeight = height[i];
		}
	}

	cout << bound << " " << currentHeight << " ";
	cout << bound << " " << height[bound] << endl;

	system("pause");
	return 0;
}