/* DFS 
 * 從高到低滑雪的最遠距離*/

#include <bits/stdc++.h>
#define INF (((1 << 30) - 1) << 1) | 1
using namespace std;

int graph[105][105] = {0};  // 每個點的高度
int longest[105][105];      // 每個點可走的最遠距離

void init() {
    memset(graph, 0, sizeof(graph));
    memset(longest, 0, sizeof(longest));
}

int dfs(int row, int column) {
    if (longest[row][column])
        return longest[row][column];

    longest[row][column] = 1;

    //判斷走上下左右，哪個點可走最遠
    if (graph[row + 1][column] < graph[row][column])
        longest[row][column] =
            max(dfs(row + 1, column) + 1, longest[row][column]);
    if (graph[row - 1][column] < graph[row][column])
        longest[row][column] =
            max(dfs(row - 1, column) + 1, longest[row][column]);
    if (graph[row][column + 1] < graph[row][column])
        longest[row][column] =
            max(dfs(row, column + 1) + 1, longest[row][column]);
    if (graph[row][column - 1] < graph[row][column])
        longest[row][column] =
            max(dfs(row, column - 1) + 1, longest[row][column]);
    return longest[row][column];
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        init();
        char name[100];
        int R, C;
        scanf("%s %d %d", name, &R, &C);
        // 防止滑出界(周圍設高度極高)
        for (int i = 0; i <= R + 1; i++)
            graph[i][0] = graph[i][C + 1] = INF;
        for (int i = 0; i <= C + 1; i++)
            graph[0][i] = graph[R + 1][i] = INF;

        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++)
                scanf("%d", &graph[i][j]);
        }
        // 找最長
        int maxrun = 0;
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                maxrun = max(maxrun, dfs(i, j));
        printf("%s: %d\n", name, maxrun);
    }

    return 0;
}