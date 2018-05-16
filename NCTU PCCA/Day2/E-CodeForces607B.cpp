/* (DP)
 * 给你一个长度为n的字符串，每次你可以消去一段连续的回文子串，剩下的两端重新拼接成一个新的* 串，问最少需要消去多少次。*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int amount;
    scanf("%d", &amount);
    int dp[amount][amount], array[amount];
    for (int i = 0; i < amount; i++) {
        scanf("%d", &array[i]);

        for (int j = 0; j < amount; j++)
            dp[i][j] = 1 << 31 - 1;
        dp[i][i] = 1;
    }
    for (int l = 2; l <= amount; l++) {
        for (int i = 0; i + l - 1 < amount; i++) {
            int j = i + l - 1;
            if (array[i] == array[j] && l > 2)
                dp[i][j] = dp[i + 1][j - 1];
            else if (array[i] == array[j])
                dp[i][j] = 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    printf("%d", dp[0][amount - 1]);
    return 0;
}