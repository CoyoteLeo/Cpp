// ConsoleApplication1.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int Factorial(int num)
{
	unsigned long long int total = 1;
	for (int i = 1; i <= num; i++)
	{
		total = total * i;
	}
	return total;
}

int main()
{
	int n;

	while (cin >> n)
	{
		int *array = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> array[i];
		}
		sort(array, array + n);

		for (int i = 0; i < n - 1; i++)
		{
			cout << Factorial(array[i]) << "<";
		}
		cout << Factorial(array[n - 1]) << endl;
	}


	return 0;
}

