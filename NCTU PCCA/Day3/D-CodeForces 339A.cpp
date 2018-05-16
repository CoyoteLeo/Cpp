#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[101];
    scanf("%s", s);
    char num[101];
    for (int i = 0; i < strlen(s);i+=2)
        num[i / 2] = s[i]-'0';
    sort(num, num + (strlen(s) + 1) / 2);
    for (int i = 0; i < strlen(s)/2;i++)
        printf("%d+", num[i]);
    printf("%d", num[strlen(s)/2]);
    return 0;
}
