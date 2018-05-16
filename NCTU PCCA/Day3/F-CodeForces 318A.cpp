#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    if (n % 2 == 0) {
        if (k <= n / 2)
            printf("%lld", 2 * k - 1);
        else
            printf("%lld", (k - n / 2) * 2);
    } else {
        if (k <= (n + 1) / 2)
            printf("%lld", 2 * k - 1);
        else
            printf("%lld", (k - (n + 1) / 2) * 2);
    }
}