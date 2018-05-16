#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;  // 最大值
const int inf = 0x7fffffff;
int r[maxn][maxn];  // r[i][j]代表i到j的剩餘容量，初始化为原图
bool visit[maxn];   // visit[n]記錄i是否有走過
int pre[maxn];      // pre[i]代表i之前是哪個點
int m, n;
bool bfs(int s, int t)  //尋找s->的增廣路，找到則回傳true
{
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    memset(visit, false, sizeof(visit));
    pre[s] = s;
    visit[s] = true;
    q.push(s);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (r[p][i] > 0 && !visit[i]) {
                pre[i] = p;
                visit[i] = true;
                if (i == t)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}
int EdmondsKarp(int s, int t) {
    int flow = 0, d, i;
    while (bfs(s, t)) {
        d = inf;  //將初始流量設為極大
        for (i = t; i != s; i = pre[i])
            d = d < r[pre[i]][i] ? d : r[pre[i]][i];
            //路徑上最小容量(=這次可流通的最大流量)
            
        for (i = t; i != s; i = pre[i]) {
            r[pre[i]][i] -= d;  //正向減流
            r[i][pre[i]] += d;  //注意!!反向加流
        }
        flow += d;
    }
    return flow;
}

int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        // n是節點數
        // m是訊息(邊)數量(可能會有重複)
        int u, v, w;
        // u->v的容量為w
        memset(r, 0, sizeof(r));  ///
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            r[u][v] += w;
        }
        printf("%d\n", EdmondsKarp(1, n));
    }
    return 0;
}