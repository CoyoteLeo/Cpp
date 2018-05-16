/* (數論)
 * str1 只由 '+' 和 '-' 组成
 * str2 由 '+'，'-'和'?'组成
 * 初始点在原点0的位置，经过 str1 的变换最终会达到某一个位置，
 * '+'表示向右移动一个单位（+1），'-'即-1，'?'的部分可填入'+'，'-'其中一个
 * 问:在填充'?'的所有情况中，使得 str2 操作完能到达 str1 最终位置的概率是多少*/
#include <bits/stdc++.h>

double fac(int n);

int main() {
    int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
    char s1[11], s2[11];
    scanf("%s", s1);
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] == '+') {
            a1++;
        } else {
            b1++;
        }
    }
    scanf("%s", s2);
    int no = 0;
    for (int i = 0; i < strlen(s2); i++) {
        if (s2[i] == '+') {
            a2++;
        } else if (s2[i] == '-') {
            b2++;
        } else {
            no++;
        }
    }
    if ((a1 - a2) < 0 || (b1 - b2) < 0) {
        printf("%.12lf", 0.0);
    } else {
        printf("%.12lf",
               fac(no) / fac(a1 - a2) / fac(no - a1 + a2) / pow(2, no));
    }
}

double fac(int n) {
    double a = 1;
    for (int i = 1; i <= n; ++i)
        a *= i;
    return a;
}