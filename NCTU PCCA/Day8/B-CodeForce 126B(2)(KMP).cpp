/* (KMP)
 * 前綴、後綴相同，且中間曾出現過，可重疊不可完全重複 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;

#define N 1000010

int n, ;
int f[N];  // KMP 子字串索引表
           // f[i]:i 的前f[i]格(不包含第i格)跟前綴相同
int Ans = 0;
char S[N];

void Solve() {
    n = (int)strlen(S);
    f[0] = 0;
    f[1] = 0; /* 1的前一格(0)即是前綴所以不能算
                 從此格開始找與前綴相同子字串*/
    for (int i = 1; i < n; i++) {
        int j = f[i]; /* 從前綴後的j個開始找匹配
                         ->因為i的前f[i]格(不包含第i格)跟前綴相同*/
        while (j && S[j] != S[i])  // 一直匹配到直到j為0或當前位置與目標位置相等
            j = f[j];
        if (S[j] == S[i]) /* 相同時，表示第i+1個前的有j+1個與前綴相同
                             ->因為發現第i格也能繼續匹配*/
            f[i + 1] = j + 1;
        else
            f[i + 1] = 0; /* 不相同時(j=0)，表示到此結束，第i+1格須從開始匹配 */
    }
    // for (int i = 0; i < n; i++)
    //     printf("%d\n", f[i]);
    // 找答案
    for (int i = 0; i <= n; i++) {
        if (i != n)  //尋找中間與前綴最長匹配子字串
            Ans = max(Ans, f[i]);
        else {
            int now = f[i];
            if (now > Ans)  // 字尾時需檢查，中間字是否與前綴一路匹配到字尾
                now = f[now];  // 如果是，則將當前最長匹配數量改為f[now]
            Ans = now;
        }
    }
    if (Ans == 0) {
        cout << "Just a legend" << endl;
        return;
    }
    for (int i = 0; i < Ans; i++)
        printf("%c", S[i]);
    cout << endl;
}

int main() {
    scanf("%s", S);
    Solve();
    return 0;
}