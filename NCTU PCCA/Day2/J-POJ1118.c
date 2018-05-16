/* (數論)
 * 給一堆點求最多幾個點在同一線上 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int amount;
    while (scanf("%d", &amount) > 0 && amount > 0) {
        int num[700][2], length[700][700] = {0};
        for (int i = 0; i < amount; i++)
            scanf(" %d %d", &num[i][0], &num[i][1]);
        int biggest = 0;
        for (int i = 0; i < amount; i++) {
            for (int j = i + 1; j < amount; j++) {
                length[i][j] = 2;
                for (int r = j + 1; r < amount; r++) {
                    if ((float)(num[i][1] - num[j][1]) *
                            (num[i][0] - num[r][0]) ==
                        (float)(num[i][1] - num[r][1]) *
                            (num[i][0] - num[j][0]))
                        length[i][j]++;
                }
                if (length[i][j] > biggest)
                    biggest = length[i][j];
            }
        }
        printf("%d\n", biggest);
    }
    return 0;
}