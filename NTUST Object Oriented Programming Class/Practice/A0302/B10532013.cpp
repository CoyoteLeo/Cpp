#include <iostream>
#define MAX 100000
using namespace std;

void Print(int* coefficients);
int n, times, ans, counter = 0, amount;

void Differential(int* coefficients)
{
	counter++;
	if (counter > times)
	{
		coefficients[0] = 0;
	}
	else
	{
		if (counter == n)
		{
			coefficients[0] = 0;
		}
		else
		{
			for (int i = 0; i < n - counter; i++)
			{
				coefficients[i] *= n - i - counter;
			}
		}
	}
	amount = n - counter;
}

void Differential(int* coefficients, int times)
{
	int cof[MAX];
	if (times >= n)
	{
		cof[0] = 0;
	}
	else
	{
		for (int i = 0; i < n - times; i++)
		{
			cof[i] = coefficients[i];
			for (int j = 0; j < times; j++)
			{
				cof[i] *= n - j - 1;
			}
		}
	}
	amount = n - times;
	Print(cof);
}

void Print(int* coefficients)
{
	cout << coefficients[0];
	for (int i = 1; i < amount; i++)
		cout << " " << coefficients[i];
	cout << endl;
}

int main()
{
	while (cin >> n >> times)
	{
		amount = n;
		counter = 0;
		int coefficients[MAX];
		for (int i = 0; i < n; i++)
			cin >> coefficients[i];
		Differential(coefficients, times);
		for (int i = 0; i < times; i++)
		{
			Differential(coefficients);
			Print(coefficients);
		}
	}
	return 0;
}