#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[101];
    scanf("%s", s);
    int a[26] = {0};
    for (int i = 0; i < strlen(s); i++)
        a[s[i] - 'a']++;
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (a[i] >= 1)
            count++;
    }
    if (count % 2 == 0) {
        printf("CHAT WITH HER!");
    } else {
        printf("IGNORE HIM!");
    }

    return 0;
}
