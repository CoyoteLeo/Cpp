#include <iostream>
#include <string>
using namespace std;

int main()
{
    int width, height;
    string input;
    while (1)
    {
        width = 0;
        height = 0;
        cin >> input;
        while (width * height < input.size())
        {
            if (width == height)
                width = width + 1;
            else
                height = height + 1;
        }
        for (int i = 0; i < width; i = i + 1)
        {
            int seek = i;
            while (seek < input.size())
            {
                cout << input[seek];
                seek = seek + width;
            }
            cout << endl;
        }
        if (cin.eof())
            break;
    }
    return 0;
}