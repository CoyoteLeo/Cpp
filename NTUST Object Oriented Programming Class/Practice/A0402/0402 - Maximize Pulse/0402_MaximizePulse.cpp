// Name: TKG
// Date: March 18th, 2018
// Last Update: March 18th, 2018
// Problem statement: This C++ program demonstrates the solution of the problem Maximize Pulse.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Signal
{
	string sgnl;
	int numOf0;
	int numOf1;
};
vector<Signal> vSignals;
bool compare(Signal element1, Signal element2);

int main()
{
	int n = 0;
	string inputSignal;

	while (!cin.eof())
	{
		vSignals.clear();
		// Read input for n signals from each generator
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			getline(cin, inputSignal);
			Signal mySignal = { inputSignal, 0, 0 };
			vSignals.push_back(mySignal);
		}
		// Count the number of 0's and 1's
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < vSignals[i].sgnl.length(); j++)
			{
				if (vSignals[i].sgnl[j] == '0')
				{
					vSignals[i].numOf0++;
				}
				else if (vSignals[i].sgnl[j] == '1')
				{
					vSignals[i].numOf1++;
				}
			}
		}
		// Reorder the signals' sequence
		sort(vSignals.begin(), vSignals.end(), compare);
		// Output the result
		int agg = 0;
		int result = 0;
		for (auto s : vSignals)
		{
			for (int i = 0; i < s.sgnl.length(); i++)
			{
				if (s.sgnl[i] == '1')
				{
					agg++;
				}
				else
				{
					result += agg;
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}
// Intent: Compare which signal has more 1's
// Pre: Pass two Signal in the range of vSignals
// Post: Return true if the first Signal has more 1's, otherwise return false
bool compare(Signal element1, Signal element2)
{
	return element1.numOf1 * element2.numOf0 > element2.numOf1 * element1.numOf0;
}