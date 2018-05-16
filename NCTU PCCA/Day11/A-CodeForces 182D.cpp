#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int n;
int f[maxn];  // KMP 子字串索引表
              // f[i]:包含第i格在內總共有f[i]格與前綴相同
char s1[maxn], s2[maxn];

int KMP(char s[]) {
    memset(f, 0, sizeof(f));

    // 建立索引表
    n = (int)strlen(s);
    int i = 1, j = 0;  // i:當前位置 j:子字串開始比對位置
    for (int j = 0, i = 1; i < n; i++) {  // i是當前位置，所以每次比對完都要推進
        if (s[i] == s[j]) {
            f[i] = j + 1;
            j++;
        }  //一樣時j也要推進
        else {
            if (j == 0)
                f[i] = j; /*當j已經在字首且比對不同時
                            等同包含此格在內也沒有與前綴相同->f[i]=j=0*/
            else {
                while (j != 0 && s[j] != s[i])
                    j = f[j - 1];
                if (s[j] == s[i]) {
                    f[i] = j + 1;
                    j++;
                } else
                    f[i] = j; /* 當j已經在字首且比對不同時
                                 等同包含此格在內也沒有與前綴相同->f[i]=j=0 */
            }
        }
        // printf("%d\n", f[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        // if (f[i] == f[i - 1] + 1) {
        if (f[i] == 1) {
            int flag = 1;
            for (int j = i; j < n - 1; j++)
                if (f[j] != f[j + 1] - 1)
                    flag = 0;
            if (flag)
                return i;
            else
                continue;
        } else
            continue;
        // }
    }
    return n;
}

int main() {
    scanf("%s", s1);
    int a = KMP(s1);
    if (strlen(s1) % a != 0)
        a = strlen(s1);
    scanf("%s", s2);
    int b = KMP(s2);
    if (strlen(s2) % b != 0)
        b = strlen(s2);
    // printf("%d %d\n", a, b);
    if (a != b)
        printf("0");
    else {
        for (int i = 0; i < a; i++)
            if (s1[i] != s2[i]) {
                printf("0");
                return 0;
            }
        int amount = 0;
        a = strlen(s1) / a;
        b = strlen(s2) / b;
        // printf("%d %d\n", a, b);
        for (int i = 1; i <= a && i <= b; i++)
            if (a % i == 0 && b % i == 0)
                amount++;
        printf("%d", amount);
        return 0;
    }
}