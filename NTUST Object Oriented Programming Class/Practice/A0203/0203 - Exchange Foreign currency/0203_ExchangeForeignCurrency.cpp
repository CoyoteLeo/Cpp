// Name: Shen
// Date: 2018/3/6
// Last Update: 2018/3/9
// Problem statement: This program solves the problem about "exchange foreign currency". In the meantime, make students pratice how to use basic flow controll(switch/if/setw/etc..)
#include <iostream>
#include <string>  //if you want to "cin" data into string variable
#include <iomanip> //for setw
using std::cin;
using std::cout;
using std::string;//for declare string variable



void Exchange(string Country, int money);
const double CURRENCY_TWD_TO_JPY = 3.5778, CURRENCY_TWD_TO_USD = 0.0339, CURRENCY_TWD_TO_KRW= 34.1180;

int main()
{
	string country = "default";
	while (cin >> country)
	{
		int money = 0;
		cin >> money;
		//Finish receiving data, and do the flow controll to exchange money
		exchange(country, money);
		
	}
	
}

// Intent: To turn input money value from TWD to the currency of the country.
 // Pre: The country and money variables must have value.
 // Post: The function returns the currency of the country which the user types in. 
void exchange(string country, int money)
{
	//Switch can be used only with integer values.So if you want to use the "switch" flow controll, represent country as integer values.
	int countryCode = 0;
	if (country == "Japan")
		countryCode = 1;
	else if (country == "America")
		countryCode = 2;
	else if (country == "Korean")
		countryCode = 3;
	else 
	{
		cout << "We don't provide the exchange of this country.\n";
	}
	switch (countryCode)
	{
		
	case(1):
		cout << std::setw(6) << "TWD" << std::setw(12) << "JYP" << "\n";
		cout << std::setw(6) << money << std::setw(12) << money * CURRENCY_TWD_TO_JPY<<"\n";
		break;
	case(2):
		cout << std::setw(6) << "TWD" << std::setw(12) << "USD" << "\n";
		cout << std::setw(6) << money << std::setw(12) << money * CURRENCY_TWD_TO_USD << "\n";
		break;
	case(3):
		cout << std::setw(6) << "TWD" << std::setw(12) << "KRW" << "\n";
		cout << std::setw(6) << money << std::setw(12) << money * CURRENCY_TWD_TO_KRW << "\n";
		break;
	}
}