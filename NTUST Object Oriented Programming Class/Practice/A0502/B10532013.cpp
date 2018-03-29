#include <iostream>
#include <cmath>
using namespace std;

static long long f[11] = { 1, 1 };

typedef struct poly
{
	int a, b, c, d;
} poly;

void factorial()
{
	long long result = 1;
	for (int i = 2; i < 11; i++)
		f[i] = f[i - 1] * i;
}

int main()
{
	factorial();
	poly input;
	long long coef;
	while (cin >> input.a >> input.b >> input.c >> input.d)
	{
		cout << pow(input.a, input.d);
		for (int i = 2 * input.d - 1; i >= 0; i--)
		{
			coef = 0;
			for (int first = input.d - 1; first >= 0; first--)
			{
				if (2 * first > i)
					continue;
				for (int second = input.d - first; second >= 0; second--)
				{
					if (2 * first + second > i)
						continue;
					if (first * 2 + second == i)
					{
						long long temp = f[input.d] / f[first] / f[input.d - first] * pow(input.a, first);
						temp *= f[input.d - first] / f[second] / f[input.d - first - second] * pow(input.b, second);
						temp *= pow(input.c, input.d - first - second);
						coef += temp;
					}
				}
			}
			cout << " " << coef;
		}
		cout << endl;
	}
}