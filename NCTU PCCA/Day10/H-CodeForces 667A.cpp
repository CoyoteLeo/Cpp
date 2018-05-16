/* 數論 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main() {
    double d, h, v, e;
    scanf("%lf %lf %lf %lf", &d, &h, &v, &e);
    double area = d * d * M_PI / 4.0;
    v /= area;
    if (e > v) {
        printf("NO");
        return 0;
    }
    long double t = (long double)h / (v - e);
    if (t <= 10000.0) {
        printf("YES\n%.12Lf", t);
    }
    // int time = 0;

    return 0;
}