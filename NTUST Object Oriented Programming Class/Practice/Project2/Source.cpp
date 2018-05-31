#include "Calculator.h"
#include"Number.h"
#include"Integer.h"
#include"Decimal.h"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	Integer x;
	Decimal y;

	cin >> x; // ¿é¤J 123456789
	cin >> y; // ¿é¤J 3.1415926

	cout << x + y << endl;
	cout << x - y << endl;
	cout << x * y << endl;
	cout << x / y << endl;

	Integer w = "1";
	Decimal z = "13.0";

	vector<Number*> nums;
	nums.push_back(new Integer(1));
	nums.push_back(new Decimal(13.0));
	for (const auto& num : nums)
		cout << num << endl;
	Calculator c;
	while (c.fetchInput())
	{
	}
	return 0;
}