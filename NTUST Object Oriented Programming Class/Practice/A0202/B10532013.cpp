#include <iostream>
using namespace std;

int main()
{
	int height[1001] = { 0 };
	int x1, h, x2;
	while (cin >> x1 && cin >> h && cin >> x2)
	{
		for (int i = x1; i < x2; i++)
		{
			if (h > height[i])
				height[i] = h;
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		if (height[i] != height[i + 1])
		{
			cout << i + 1 << " " << height[i] << " " << i + 1 << " " << height[i + 1] << " ";
		}
	}
	return 0;
}