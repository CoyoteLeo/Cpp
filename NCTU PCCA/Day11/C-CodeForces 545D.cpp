#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main() {
    int n, amount = 0, t[maxn];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    sort(t, t + n);
    unsigned long long int accumlate = 0;
    for (int i = 0; i < n; i++) {
        if (accumlate <= t[i])
            amount++;
        else {
            while (i < n && t[i] < accumlate)
                i++;
            if (i < n)
                amount++;
            else
                break;
        }
        accumlate += t[i];
    }
    printf("%d", amount);
    return 0;
}