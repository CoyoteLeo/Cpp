

// 陣列超過可宣告的大小，將graph拆開
#include <bits/stdc++.h>
using namespace std;

const int max_r = (1e5 + 10) * 2;
pair<pair<int, int>, int> roads[max_r]; // 起點,終點,寬度

const int max_v = 1e5 + 10;
int first[maxn];  // first[i]:到i點之路徑的起始點
int pre[maxn];    // 每個點之前的點
// int res[maxn];    //
long long spend[maxn];             // 紀錄出發點到i的最短距離(時間)
const int max_r = (1e5 + 10) * 2;  // 無向圖->雙向
int e;                             //
int v[maxm];                       //
int next_[maxm];                   //
int w[maxm];                       //

int target, roads;
// int graph[max_v][max_v];
bool visit[max_v] = {0};
int pre[max_v] = {0};

int dij(int target) {
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= target; i++) {
        spend[i] = graph[1][i];
        pre[i] = 1;
    }
    spend[1] = 0;  // 出發點到出發點
    visit[1] = 1;
    pre[1] = 0;
    for (int i = 2; i <= target; i++) {
        int min_spend = INF;
        int min_point = -1;
        for (int j = 1; j <= target; j++) {  // 找目前點所到的地方最短的距離
            if (!visit[j] && spend[j] < min_spend) {
                min_point = j;
                min_spend = spend[j];
            }
        }
        if (min_point == -1)  // 所有點都走完了
            break;
        visit[min_point] = true;             // 把位置推進到那一格
        for (int j = 1; j <= target; j++) {  // 更新那一格附近的格子
            if (!visit[j])
                if (spend[j] > spend[min_point] + graph[min_point][j]) {
                    pre[j] = min_point;
                }
            spend[j] = min(spend[j], spend[min_point] + graph[min_point][j]);
        }
    }
    // for (int i = 1; i <= target; i++)
    //     printf("%d\n", pre[i]);
    return spend[target];
}
int main() {
    scanf("%d%d", &target, &roads);
    memset(spend, 1, sizeof(spend));
    for (int i = 0,count=0, a, b, c; i < roads; i++) {
        scanf("%d%d%d", &a, &b, &c);

        graph[b][a] = graph[a][b] = min(graph[a][b], c);
    }
    dij(target);
    int tmp = target;
    stack<int> ans;
    ans.push(target);
    while (pre[tmp] != 1) {
        ans.push(pre[tmp]);
        tmp = pre[tmp];
    }
    ans.push(1);
    while (!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    // printf("%d\n", dij(target));
    return 0;
}