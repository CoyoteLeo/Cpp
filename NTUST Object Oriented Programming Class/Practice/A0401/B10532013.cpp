#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#define SUBMAX 2001
using namespace std;

int main()
{
	string row1;
	char newline;
	int i;
	float target, num[30], sub[30], subMin = SUBMAX;
	bool first;
	while (getline(cin, row1))
	{
		istringstream input(row1);
		cin >> target;
		i = 0;
		while (input >> num[i])
		{
			sub[i] = abs(target - num[i]);
			subMin = subMin > sub[i] ? sub[i] : subMin;
			i++;
		}
		first = true;
		for (int j = 0; j < i; j++)
		{
			if (sub[j] == subMin)
			{
				if (first)
				{
					cout << num[j];
					first = false;
				}
				else
					cout << " + " << num[j];
			}
		}
		cout << endl;
		cin >> newline;
	}
	return 0;
}