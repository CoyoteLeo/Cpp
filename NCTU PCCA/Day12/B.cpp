#include <bits/stdc++.h>
using namespace std;

int main() {
    int test, n;
    scanf("%d", &test);
    while(test--){
        int alpha[26] = {0};
        scanf("%d", &n);
        char s[n];
        scanf("%s", s);
        for (int i = 0; i < n;i++)
            alpha[s[i] - 'a']++;
        int m = 0;
        for (int i = 0; i < 26;i++)
            m = max(m, alpha[i]);
        printf("%d\n", m);
    }
}