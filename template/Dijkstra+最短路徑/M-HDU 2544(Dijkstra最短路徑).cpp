/* http://wiki.mbalib.com/zh-tw/Dijkstra%E7%AE%97%E6%B3%95 */
/* 標準Dijkstra求最短路徑 */

#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int INF = 0xfffffff;

int target, road;
int graph[205][205];
int spend[205];  // 紀錄出發點到i的最短距離(時間)
bool visit[205];

int dij(int target) {
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= target; i++)
        spend[i] = graph[1][i];
    spend[1] = 0;  // 出發點到出發點
    visit[1] = 1;
    for (int i = 2; i <= target; i++) {
        int min_spend = INF;
        int min_point = -1;
        for (int j = 1; j <= target; j++) {  // 尚未走過的點中，離起點最近的點
            if (!visit[j] && spend[j] < min_spend) {
                min_point = j;
                min_spend = spend[j];
            }
        }
        if (min_point == -1)  // 直到每個都走過(以最短路徑的方式走完整個圖能走到的地方了)
            break;
        visit[min_point] = true;             // 把位置推進到那一格
        for (int j = 1; j <= target; j++) {  // 更新那一格附近的格子
            if (!visit[j])
                spend[j] =
                    min(spend[j], spend[min_point] + graph[min_point][j]);
        }
    }
    return spend[target];
}
int main() {
    while (scanf("%d%d", &target, &road) > 0) {
        if (target <= 0 || road <= 0)
            break;
        memset(graph, 1, sizeof(graph));
        memset(spend, 1, sizeof(spend));
        for (int i = 0, a, b, c; i < road; i++) {
            scanf("%d%d%d", &a, &b, &c);
            graph[b][a] = graph[a][b] = min(graph[a][b], c);  // 雙向圖
        }
        printf("%d\n", dij(target));
    }
    return 0;
}