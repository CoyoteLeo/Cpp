/* DFS 
 * 機器人行走遠距離(只會有一條路) */

#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;

int graph[15][15] = {0};
int direct[15][15] = {0};  // 第一次經過時的方向
bool visit[15][15] = {0};
int sum = 0;

void dfs(int x, int y, int dir) {
    if (!visit[x][y]) {
        sum++;
        direct[x][y] = dir;
        visit[x][y] = true;
    }
    for (int i = 0; i < 4; i++) {
        int dir1 = (dir + i) % 4;
        if (dir1 == 0) {
            if (graph[x-1][y]) {
                if (direct[x-1][y] == dir1)
                    break;
                dfs(x-1, y, dir1);
                break;
            }
        } else if (dir1 == 1) {
            if (graph[x][y+1]) {
                if (direct[x][y+1] == dir1)
                    break;
                dfs(x, y+1, dir1);
                break;
            }
        } else if (dir1 == 2) {
            if (graph[x+1][y]) {
                if (direct[x+1][y] == dir1)
                    break;
                dfs(x+1, y, dir1);
                break;
            }
        } else if (dir1 == 3) {
            if (graph[x][y-1]) {
                if (direct[x][y-1] == dir1)
                    break;
                dfs(x, y-1, dir1);
                break;
            }
        }
    }
}
int main() {
    memset(direct, 1, sizeof(direct));
    int w, h;
    scanf("%d%d", &w, &h);
    int direction, x, y;
    for (int i = 1; i <= w; i++) {
        char s[h + 1];
        scanf("%s", s);
        for (int j = 0; j < h; j++) {
            if (s[j] == '.')
                graph[i][j + 1] = 1;
            else if (s[j] == '*')
                graph[i][j + 1] = 0;
            else {
                graph[i][j + 1] = 1;
                x = i;
                y = j + 1;
                if (s[j] == 'U')
                    direction = 0;
                else if (s[j] == 'R')
                    direction = 1;
                else if (s[j] == 'D')
                    direction = 2;
                else if (s[j] == 'L')
                    direction = 3;
            }
        }
    }
    dfs(x, y, direction);
    printf("%d", sum);
}