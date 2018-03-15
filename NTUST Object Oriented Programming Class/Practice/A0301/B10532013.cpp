#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	while (cin >> input)
	{
		int len = input.length(), counter = 0, start = 0, num[52];
		for (; start < len; counter++, start++)
		{
			if (input[start] != '0')
				break;
		}
		for (int i = 0; start + i < len; i++)
		{
			num[i] = (int)input[start + i] - (int)'0';
		}
		len -= counter;
		for (; len > 1; counter--)
		{
			for (int j = 0; j < counter - 1; j++)
			{
				num[j] += num[j + 1];
			}
		}
		cout << num[0] << endl;
	}
	return 0;
}