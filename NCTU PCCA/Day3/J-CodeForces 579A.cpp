#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, count = 1;
    scanf("%d", &n);
    while (n != pow(2, (int)log2(n))) {
        count++;
        n = (int)(n - pow(2, (int)log2(n)));
    }
    printf("%d", count);
    return 0;
}
