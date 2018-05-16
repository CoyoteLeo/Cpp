/* (數論)1-n的数字中，存在几个数字，他有质因数且只有两个，并且这两个质因数都是質数 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int MAX;
    scanf("%d", &MAX);
    MAX++;
    int num[MAX] = {0};
    bool no_prime[MAX] = {false};
    int count = 0;
    for (int i = 2; i < MAX; i++) {
        if (!no_prime[i]) {
            for (int counter = 1; i * counter < MAX; counter++) {
                num[i * counter]++;
                no_prime[i * counter] = true;
            }
        }
        if (num[i] == 2) {
            count++;
        }
    }
    printf("%d", count);
}