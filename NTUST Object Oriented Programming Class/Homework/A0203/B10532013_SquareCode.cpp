#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int length, height;
    while (cin >> input)
    {
        length = input.length();
        height = ceil(sqrt(length));
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; i + j * height < length; j++)
            {
                cout << input[i + j * height];
            }
            cout << endl;
        }
    }
    return 0;
}