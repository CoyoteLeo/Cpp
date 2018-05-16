/* (數論)
 * 問子集合最大總和*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int amount;
    scanf(" %d", &amount);
    int num[amount];
    int sum = 0, smallest, flag_a = 0, biggest, flag_b = 0;
    for (int i = 0; i < amount; i++) {
        scanf("%d", &num[i]);
        if (num[i] >= 0) {
            sum += num[i];
            if ((!flag_a || num[i] < smallest) && num[i] % 2 != 0) {
                smallest = num[i];
                flag_a = 1;
            }
        } else {
            if ((!flag_b || num[i] > biggest) && num[i] % 2 != 0) {
                biggest = num[i];
                flag_b = 1;
            }
        }
    }
    if (sum % 2 == 0) {
        if (!flag_a)
            printf("%d", sum + biggest);
        else if (!flag_b)
            printf("%d", sum - smallest);
        else if (sum - smallest > sum + biggest)
            printf("%d", sum - smallest);
        else
            printf("%d", sum + biggest);
    } else {
        printf("%d", sum);
    }
    return 0;
}