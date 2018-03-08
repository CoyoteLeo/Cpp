#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string country;
	float money;
	float currencyTWDToJPY = 3.5778, currencyTWDToUSD = 0.0339, currencyTWDToKRW = 34.1180;
	while (cin >> country)
	{
		cin >> money;
		if (country == "Japan")
		{
			cout << setw(6) << "TWD" << setw(12) << "JYP" << endl;
			cout << setw(6) << money << setw(12) << money * currencyTWDToJPY << endl;
		}
		else if (country == "America")
		{
			cout << setw(6) << "TWD" << setw(12) << "USD" << endl;
			cout << setw(6) << money << setw(12) << money * currencyTWDToUSD << endl;
		}
		else if (country == "Korean")
		{
			cout << setw(6) << "TWD" << setw(12) << "KRW" << endl;
			cout << setw(6) << money << setw(12) << money * currencyTWDToKRW << endl;
		}
		else
		{
			cout << "We don't provide the exchange of this country." << endl;
		}
	}
	return 0;
}