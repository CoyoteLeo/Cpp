#include <bits/stdc++.h>
using namespace std;
unsigned long long fac(int n);

int main() {
    int test, n;
    scanf("%d", &test);
    while (test--) {
        int amount = 0;
        int num[100];
        for (int i = 0, count = 0, tmp; i < 10; i++) {
            scanf("%d", &tmp);
            while (tmp--)
                num[count++] = i;
        }
        for (int i = 0; i < 9; i++)
            printf("%d\n", num[i]);
        // for (int len = 4; i <= 9; i++) {
        for (int a = 0; a < count - len; a++)
            for (int b = a + 1; b < count - len + 1; b++)
                for (int c = b + 1; c < count - len + 2; c++)
                    for (int d = c + 1; d < count; d++){
                        
                    }
        // }
    }
}

unsigned long long fac(int n) {
    unsigned long long a = 1;
    for (int i = 1; i <= n; ++i)
        a *= i;
    return a;
}