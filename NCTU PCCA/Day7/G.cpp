#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;

typedef struct worker {
    int setuptime;
    int need;
    int sum;
} worker;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    worker workers[n + 1];
    int t[m] = {0};
    for (int i = 0; i < m; i++)
        scanf("%d", &t[i]);
    sort(t, t + m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &workers[i].setuptime, &workers[i].need);
        workers[i].sum = 0;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            int remain = t[i] - workers[j].setuptime;
            if (remain <= 0 || workers[j].need <= 0)
                continue;
            else {
                workers[j].sum++;
                workers[j].need -= remain;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (workers[i].need > 0)
            printf("0 ");
        else
            printf("%d ", workers[i].sum);
    return 0;
}