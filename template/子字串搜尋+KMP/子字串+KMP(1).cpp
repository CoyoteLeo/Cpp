/* 教學網站:https://www.youtube.com/watch?v=GTJr8OvyEVQ&index=5&list=PLrmLmBdmIlpvm7VaC0NTR27A_3i2sU3zd&t=591s
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;

#define maxn 1000010

int n;
int f[maxn];  // KMP 子字串索引表
              // f[i]:包含第i格在內總共有f[i]格與前綴相同
char s[maxn];

void KMP() {
    int Ans = 0;

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
    }
    //  找答案
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            Ans = max(Ans, f[i]);  // 找中間與前綴最多有「幾個字符」匹配
        else {
            int now = f[i];
            if (now > Ans) /*當中間字與前綴一路匹配到字尾時須修正
                             (因為中間與後綴不可完全重疊)=字尾匹配數最大時*/
                Ans = f[now - 1];
            else
                Ans = now;
            break;
        }
    }
    if (Ans <= 0) {
        cout << "Just a legend" << endl;
        return;
    }
    for (int i = 0; i < Ans; i++)
        printf("%c", s[i]);
}

int main() {
    scanf("%s", s);
    KMP();
    return 0;
}
