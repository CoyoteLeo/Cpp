#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double n, r, guess, temp;
    while (cin >> n)
    {
        guess = n / 2;
        do
        {
            temp = guess;
            r = n / guess;
            guess = (guess + r) / 2;
        } while (guess - temp > 0.001 || temp - guess > 0.001);
        cout << fixed << setprecision(2) << guess << endl;
    }
    return 0;
}