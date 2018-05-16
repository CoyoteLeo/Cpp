#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[(int)1e5+1];
    char s1[(int)1e5+1];
    scanf("%s", s);
    strcpy(s1, s);
    int len = strlen(s), flag_a = 0, flag_b = 0;
    for (int i = 1; i < len; i++) {
        if (s[i - 1] == 'A' && s[i] == 'B') {
            flag_a = 1;
            s[i - 1] = s[i] = 'C';
            break;
        }
    }
    for (int i = 1; i < len; i++) {
        if (s[i - 1] == 'B' && s[i] == 'A') {
            flag_b = 1;
            break;
        }
    }
    if (flag_a && flag_b) {
        printf("YES");
    } else {
        flag_a = flag_b = 0;
        for (int i = 1; i < len; i++) {
            if (s1[i - 1] == 'B' && s1[i] == 'A') {
                flag_a = 1;
                s1[i - 1] = s1[i] = 'C';
                break;
            }
        }
        for (int i = 1; i < len; i++) {
            if (s1[i - 1] == 'A' && s1[i] == 'B') {
                flag_b = 1;
                break;
            }
        }
        if (flag_a && flag_b)
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}