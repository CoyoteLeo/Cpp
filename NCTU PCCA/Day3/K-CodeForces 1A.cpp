#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    scanf(" %d %d %d", &n, &m, &a);
    if (n % a != 0 && m % a != 0) {
        printf("%.0lf", ((double)(n / a) + 1) * ((m / a) + 1));
    } else if (n % a != 0 && m % a == 0) {
        printf("%.0lf", ((double)(n / a) + 1) * ((m / a)));
    } else if (n % a == 0 && m % a != 0) {
        printf("%.0lf", ((double)(n / a)) * ((m / a) + 1));
    } else if (n % a == 0 && m % a == 0) {
        printf("%.0lf", ((double)(n / a)) * ((m / a)));
    }
}