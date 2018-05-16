#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[1001] = {0};
    int t = 0;
    while (scanf("%d", &t) != EOF) {
        scanf("%s", s);
        bool flag = true;
        int a[26] = {0};
        for (int i = 0; i < strlen(s); i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (a[i] % t != 0)
                flag = false;
        if (flag) {
            for (int i = 0; i < t; i++) {
                for (int j = 0; j < 26; j++) {
                    for (int r = 0; r < a[j] / t; r++)
                        printf("%c", j + 'a');
                }
            }
        } else {
            printf("-1");
        }
    }
    return 0;
}