#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int graph[maxn][maxn] = {0};
int ans[maxn][maxn] = {0};

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        memset(graph, 0, sizeof(graph));
        memset(ans, 0, sizeof(ans));
        int n, m = 0;
        scanf(" %d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &graph[i][j]);
                ans[i][j] += graph[i][j];
                int x = i, y = j, flag_a = 0, flag_b = 0;
                while (--x > 0 && --y > 0) {
                    flag_a = 1;
                    ans[i][j] += graph[i][j];
                }
                x = i, y = j;
                while (flag_a && (++x) <= n && --y > 0) {
                    flag_b = 1;
                    ans[i][j] += graph[i][j];
                }
                if (!flag_a || !flag_b)
                    ans[i][j] = 0;
                m = max(m, ans[i][j]);
            }
        }
        printf("%d\n", m);
    }
}