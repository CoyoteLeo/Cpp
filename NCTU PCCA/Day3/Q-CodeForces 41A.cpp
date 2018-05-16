#include <bits/stdc++.h>
using namespace std;

int main() {
    char s1[101], s2[101];
    scanf("%s", s1);
    scanf("%s", s2);
    int flag = 1, len = strlen(s1);
    for (int i = 0; i < len; i++) {
        if (s1[i] != s2[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
