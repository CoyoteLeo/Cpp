#include <bits/stdc++.h>
using namespace std;

int graph[105][105];
queue<int> q;
int pre[105];

//尋找從起點到終點的一條路徑
bool bfs(int s, int t, int n) {
    memset(pre, 0, sizeof(pre));  // 清空紀錄(是否走過)
    while (!q.empty())            // 清空佇列
        q.pop();

    // bfs開始
    pre[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            //尚未走過且流量>0
            if (pre[i] == 0 && graph[cur][i] > 0) {
                pre[i] = cur;  // 將第i個節點的前一個點設為cur
                if (i == t)    // 抵達終點
                    return true;
                q.push(i);  // 從i點繼續找未走過且目標抵達t
            }
        }
    }
    return false;
}
int ek(int s, int t, int n) {
    int maxflow = 0;
    while (bfs(s, t, n))  //直到不能再從起點走到終點
    {
        int minflow = 1e7;  //將初始流量設最大
        for (int i = t; i != s; i = pre[i]) {
            minflow = min(minflow, graph[pre[i]][i]);
            //路徑上最小容量(=這次可流通的最大流量)
        }
        for (int i = t; i != s; i = pre[i]) {
            graph[pre[i]][i] -= minflow;  //正向減流
            graph[i][pre[i]] += minflow;  //注意!!反向加流
        }
        maxflow += minflow;
    }

    return maxflow;
}
int main() {
    int n;
    int test = 1;
    while (scanf("%d", &n) > 0 && n > 0) {
        memset(graph, 0, sizeof(graph));
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        for (int i = 0; i < c; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            graph[a][b] = (graph[b][a] += w);
        }
        printf("Network %d\n", test++);
        printf("The bandwidth is %d.\n\n", ek(s, t, n));
    }
    return 0;
}