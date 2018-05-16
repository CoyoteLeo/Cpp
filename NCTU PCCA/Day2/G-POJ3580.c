/* 硬爆->TLE 未解 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int amount;
    scanf("%d", &amount);
    int num[100000 + 1];
    for (int i = 1; i <= amount; i++)
        scanf("%d", &num[i]);
    int command;
    scanf("%d", &command);
    // printf("%d %d\n", amount, command);
    for (int i = 0; i < command; i++) {
        char s[10];
        int x, y, D, T, P;
        scanf("%s", s);
        if (strcmp(s, "ADD") == 0) {
            scanf(" %d %d %d", &x, &y, &D);
            for (int j = x; j <= y; j++)
                num[j] += D;
            // for (int r = 0; r < amount; r++)
            //     printf("%d\n", num[r]);
        } else if (strcmp(s, "REVERSE") == 0) {
            scanf(" %d %d", &x, &y);
            int n = y - x + 1;
            int tmp[10000];
            for (int r = 0; r < n; r++)
                tmp[r] = num[y - r];
            for (int r = 0; r < n; r++)
                num[x + r] = tmp[r];
        } else if (strcmp(s, "REVOLVE") == 0) {
            scanf(" %d %d %d", &x, &y, &T);
            int n = y - x + 1;
            T %= n;
            int tmp[10000][2];
            for (int r = 0; r < n; r++) {
                tmp[r][0] = x + ((r + T) % n);
                tmp[r][1] = num[x + r];
            }
            for (int r = 0; r < n; r++)
                num[tmp[r][0]] = tmp[r][1];
        } else if (strcmp(s, "INSERT") == 0) {
            scanf(" %d %d", &x, &P);
            for (int r = 0; r < amount - x; r++)
                num[amount - r + 1] = num[amount - r];
            num[x + 1] = P;
            amount++;
        } else if (strcmp(s, "DELETE") == 0) {
            scanf(" %d", &x);
            for (int r = x; r < amount; r++)
                num[r] = num[r + 1];
            num[amount--] = 0;
        } else {
            scanf(" %d %d", &x, &y);
            int min = 1 << 31;
            min--;
            for (int r = x; r <= y; r++) {
                if (min > num[r])
                    min = num[r];
            }
            printf("%d\n", min);
        }
        for (int r = 1; r <= amount; r++)
            printf("%d\t", num[r]);
        puts("");
    }
    return 0;
}