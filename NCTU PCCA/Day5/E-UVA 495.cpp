/* 數論+暴力+大數 */

#include <bits/stdc++.h>
#define INF (((1 << 30) - 1) << 1) | 1
using namespace std;

int num[5000 + 1][(int)2000] = {0};
int now = 1, amount = 1;

void add(int n) {
    for (int i = 0; i < 2000; i++) {
        num[now][i] += num[now - 1][i] + num[now - 2][i];
        num[now][i + 1] += (num[now][i] / 10);
        num[now][i] %= 10;
        // num[now][i + 1] += digit / 10;
        // num[now][i] += digit % 10;
    }
}

void fab(int x) {
    while (x > now)
        add(++now);
}

int main() {
    num[0][0] = 0;
    num[1][0] = 1;
    int x;
    while (scanf("%d", &x) > 0) {
        printf("The Fibonacci number for %d is ", x);
        if (x == 0) {
            printf("%d\n", 0);
            continue;
        }
        fab(x);
        int i;
        for (i = 1999; i >= 0; i--) {
            if (num[x][i] != 0)
                break;
        }
        if (i == -1)
            printf("0");
        else
            for (; i >= 0; i--)
                printf("%d", num[x][i]);
        printf("\n");
    }
    return 0;
}