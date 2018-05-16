#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int num[n], bad[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    sort(num, num + n);
    int add = 0, st = 0, ed = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] == num[i - 1]) {
            num[i]++;
            add++;
        } else if (num[i] < num[i - 1]) {
            add += num[i - 1] - num[i] + 1;
            num[i] += num[i - 1] - num[i] + 1;
        }
    }
    printf("%d\n", add);
    return 0;
}
