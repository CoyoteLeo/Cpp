/* (DP)
 * Marmot 吃两种类型的花：red 或者 white
 * 如果要吃 white 这种花，就需要吃连续 k 朵 white；
 * 而如果吃 red，就没有这种限制。
 * 给定区间[a, b]，问总共的吃法有多少种。*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    const int MAX = (int)1e5 + 1, mod = (int)1e9 + 7;
    int t, k;
    int min, max;
    int table[MAX] = {0};
    scanf(" %d %d", &t, &k);
    for (int i = 0; i < k; i++)
        table[i] = 1;
    for (int i = k; i < MAX; i++) {
        table[i] = table[i - 1] + table[i - k];
        table[i] %= mod;
    }
    int sum[MAX] = {0};
    for (int i = 1; i < MAX; i++) {
        sum[i] = table[i] + sum[i - 1];
        sum[i] %= mod;
    }
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &min, &max);
        printf("%d\n", (sum[max] - sum[min - 1] + mod) % mod);
    }
    return 0;
}