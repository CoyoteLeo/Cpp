#include<iostream>
using namespace std;

int main(void)
{
    long long int inputSeconds;
    while (cin >> inputSeconds)
    {
        cout << inputSeconds / 3600 << " hours " << inputSeconds / 60 % 60 << " minutes and " << inputSeconds % 60 << " seconds" << endl;
    }
    return 0;
}