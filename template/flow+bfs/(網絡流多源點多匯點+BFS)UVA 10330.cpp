#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7fffffff;
const int tmp = 100 + 5;
const int maxn = 300;
int flow[maxn][maxn];
queue<int> q;
int pre[maxn];


//尋找從起點到終點的一條路徑
bool bfs(int s, int t, int n) {
    bool visit[maxn] = {false};
    fill(pre, pre + n + 2, -1);  // 清空紀錄(是否走過)
    while (!q.empty())           // 清空佇列
        q.pop();

    // bfs開始
    pre[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i <= n + tmp + 1; i++) {
            //尚未走過且流量>0
            if (!visit[i] && flow[cur][i] > 0) {
                pre[i] = cur;  // 將第i個節點的前一個點設為cur
                visit[i] = true;
                if (i == t)  // 抵達終點
                    return true;
                q.push(i);  // 從i點繼續找未走過且目標是抵達t
            }
        }
    }
    return false;
}
int ek(int s, int t, int n) {
    int maxflow = 0;
    while (bfs(s, t, n)) {
        //直到不能再從起點走到終點

        int minflow = INF;  //將初始流量設最大
        for (int i = t; i != s; i = pre[i]) {
            minflow = min(minflow, flow[pre[i]][i]);
            if (!minflow)
                break;
            //路徑上最小容量(這次可流通的最大流量)
        }
        if (!minflow)
            continue;

        for (int i = t; i != s; i = pre[i]) {
            flow[pre[i]][i] -= minflow;  //正向減流
            flow[i][pre[i]] += minflow;  //注意!!反向加流
        }
        maxflow += minflow;
    }
    return maxflow;
}
int main() {
    int n;
    while (scanf(" %d", &n) != EOF) {
        memset(flow, 0, sizeof(flow));

        // 將節點分為一條路->頭:i,尾:i+tmp
        for (int i = 1, x; i <= n; i++) {
            scanf(" %d", &x);
            flow[i][i + tmp] = x;
        }
        int m;
        scanf(" %d", &m);
        for (int i = 0, a, b, w; i < m; i++) {
            scanf(" %d%d%d", &a, &b, &w);
            flow[a + tmp][b] += w;
        }
        int B, D;
        scanf(" %d%d", &B, &D);

        // 將多源點合為單一超級源點
        for (int i = 0, x; i < B; i++) {
            scanf(" %d", &x);
            flow[0][x] = INF;
        }
        // 將多匯點合為單一超級匯點
        for (int i = 0, x; i < D; i++) {
            scanf(" %d", &x);
            flow[x + tmp][n + 1] = INF;
        }
        printf("%d\n", ek(0, n + 1, n + 1));
    }
    return 0;
}