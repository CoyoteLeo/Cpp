#include <iostream>
using namespace std;

template <typename t>
double absoluteValue(t a, t b)
{
    double result = (double)a - (double)b;
    return (result < 0 ? result * -1 : result);
}

int main()
{
    int i1, i2;
    double d1, d2;
    char c1, c2;
    float f1, f2;
    i1 = 10;
    i2 = 20;
    cout << "Absolute value of 10, 20 is " << absoluteValue(i1, i2) << endl;

    d1 = 5.5;
    d2 = 3.1;
    cout << "Absolute value of 5.5, 3.1 is " << absoluteValue(d1, d2) << endl;

    c1 = 'A', c2 = 'C';
    cout << "Absolute value of A, C is " << absoluteValue(c1, c2) << endl;

    f1 = 25.0;
    f2 = 13.55;
    cout << "Absolute value of 25.0, 13.55 is " << absoluteValue(f1, f2) << endl;
    system("pause");
    return 0;
}