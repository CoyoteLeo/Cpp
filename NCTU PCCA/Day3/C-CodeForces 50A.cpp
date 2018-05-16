#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, count = 0;
    scanf("%d %d", &n, &m);
    if (n * m % 2 == 0) {
        printf("%d", n * m / 2);
    } else {
        printf("%d", (n * m-1) / 2);
    }
    return 0;
}
