/* (DP)
 * 给你一连串字符串，问你下一个字符串尾字母等于前一个字符首字母
 * 最后一个字符串尾字母等于首串首字母，这样的构造出的字符串最长为多少。*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int table[26][26] = {0};
    int amount;
    scanf("%d", &amount);
    for (int i = 0; i < amount; i++) {
        char s[11];
        scanf("%s", s);
        int len = strlen(s);
        int st = s[0] - 'a', ed = s[len - 1] - 'a';
        for (int i = 0; i < 26; i++)
            if (table[i][st] != 0) {
                /* key point */
                table[i][ed] = max(table[i][st] + len, table[i][ed]);
            }
        table[st][ed] = max(table[st][ed], len);
    }
    int longest = 0;
    for (int i = 0; i < 26; i++) {
        longest = max(table[i][i], longest);
    }
    printf("%d", longest);
    return 0;
}