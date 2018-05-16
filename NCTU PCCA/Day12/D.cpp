#include <bits/stdc++.h>
#define FORi(to) for (int i = 0; i < to; i++)
#define FORk(to) for (int k = 0; k < to; k++)
#define FORi1(to) for (int i = 1; i <= to; i++)
#define PI 3.14159265359
using namespace std;
typedef long long LL;
int in() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    int t = in();
    while (t--) {
        double a, b;
        cin >> a >> b;
        double ah = a / 2;
        double caDis = (ah * ah * PI - b);
        double k2 = a * a;
        double sqSide = a / sqrt(2);
        double sqDis = sqSide * sqSide - b;
        if (caDis > (-0.001) && caDis < (0.001)) {
            printf("Circle; %.7lf\n", a * PI);
            continue;
        } else if (sqDis > (-0.001) && sqDis < (0.001)) {
            printf("Square: %.7lf\n", 4 * sqSide);
            continue;
        } else {
            printf("You liar!\n");
        }
    }
}