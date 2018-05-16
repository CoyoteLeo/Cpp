#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[17];
    scanf("%s", s);
    if (atoi(&s[strlen(s) - 1]) % 2 == 0)
        printf("%.0lf", (atof(s) / 2));
    else
        printf("%.0lf", ((atof(s)-1) / 2) - atof(s));
    return 0;
}