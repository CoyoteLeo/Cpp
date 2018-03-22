#include <algorithm>
#include <iostream>
#include <string>
#define MAX 9999
using namespace std;

typedef struct input
{
	string str;
	int one;
	int zero;
	double level;
} input;

bool compareLevel(const input &a, const input &b)
{
	if (a.level == b.level)
		return a.one > b.one;
	else
		return a.level > b.level;
}
int main()
{
	int amount, one, zero, i, j, result;
	input record[MAX];
	string in;
	while (cin >> amount)
	{
		for (i = 0; i < amount; i++)
		{
			cin >> in;
			one = 0;
			zero = 0;
			long long level = 0, total = 0;
			for (j = 0, one = 0, zero = 0; j < in.size(); j++)
			{
				if (in[j] == '1')
					one++;
				else
					zero++;
			}
			record[i].str = in;
			record[i].one = one;
			record[i].zero = zero;
			record[i].level = (one / (double)zero);
		}
		sort(record, record + amount, compareLevel);
		one = result = 0;
		for (i = 0; i < amount; i++)
		{
			for (j = 0; j < record[i].str.size(); j++)
			{
				if (record[i].str[j] == '1')
					one++;
				else
					result += one;
			}
		}
		cout << result << endl;
	}
	return 0;
}