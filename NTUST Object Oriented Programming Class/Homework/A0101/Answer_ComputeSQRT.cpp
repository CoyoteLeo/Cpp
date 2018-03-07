#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
    double ans = 0;
    while (cin >> ans) {
        double guess = 0, comp = 0;
        guess = ans /2;
        while (guess - comp > 0.001) {
            comp = ans / guess;
            guess = (guess + comp) / 2;
        }
        cout << fixed << setprecision(2) << comp << endl;
    }
    return 0;
}