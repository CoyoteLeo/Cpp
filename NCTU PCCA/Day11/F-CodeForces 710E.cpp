#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
unsigned long long int table[maxn];

int main() {
    unsigned long long int n, x, y;
    scanf(" %llu%llu%llu", &n, &x, &y);
    table[1] = x;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0)
            table[i] = min(table[i - 1] + x, table[i / 2] + y);
        else
            table[i] = min(table[i - 1] + x,
                           min(table[i / 2] + y + x, table[i / 2 + 1] + y + x));// 列出所有情況
    }
    printf("%llu", table[n]);
    return 0;
}