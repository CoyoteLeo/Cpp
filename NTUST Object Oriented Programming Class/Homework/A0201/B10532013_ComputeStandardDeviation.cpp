#include <cmath>
#include <iostream>
using namespace std;

void getAverageAndStandardDeviation(float input[], int amount)
{
    float total = 0.0, avg, standardDeviation, squareTotal = 0.0;
    for (int i = 0; i < amount; i++)
    {
        total += input[i];
        squareTotal += input[i] * input[i];
    }
    avg = total / amount;
    standardDeviation = sqrt(squareTotal / amount - avg * avg);
    cout << "Average:" << avg << "\t"
         << "Standard deviation:" << standardDeviation << endl;
}

int main()
{
    int amount;
    while (cin >> amount)
    {
        float input[amount];
        for (int i = 0; i<amount; i++)
        {
            cin >> input[i];
        }
        getAverageAndStandardDeviation(input, amount);
    }
    return 0;
}