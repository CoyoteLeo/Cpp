#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
int graph[10005][10005] = {0};
int visit[10005] = {0}, pre[10005] = {0};

void dfs(int x, int y, int n) {
    for (int i = 1; i <= n; i++)
        if (!visit[x][i] && graph[1][i]) {
            pre[i] = x;
        }
}
int main() {
    int n, m;
    scanf("%d", &n);
    int cost[n + 1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    scanf("%d", &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        graph[a][b] = INF;
    }
    targen(1, n, n);
}
