#include <iostream>
#define MAX 100000
using namespace std;

long long factorial(int input)
{
	long long ans = 1;
	while (input != 1)
	{
		ans *= input;
		input--;
	}
	return ans;
}

void sort(long long num[], int len)
{
	long long temp;
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1 - i; j++)
			if (num[j] > num[j + 1])
			{
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
}

int main()
{
	int amount, input;
	long long num[MAX];
	while (cin >> amount)
	{
		for (int i = 0; i < amount; i++)
		{
			cin >> input;
			num[i] = factorial(input);
		}
		sort(num, amount);
		cout << num[0];
		for (int i = 1; i < amount; i++)
			cout << "<" << num[i];
		cout << endl;
	}
	return 0;
}