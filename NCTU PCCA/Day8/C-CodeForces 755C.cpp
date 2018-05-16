/* (分組?)
 * 給定n棵樹，Pi表示i可連到Pi->求最多幾組(幾棵樹)*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;

int main() {
    int n;
    int tree[10005];
    int t = 0;
    bool group[10005] = {false};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &tree[i]);
    for (int i = 1; i <= n; i++) {
        if (!group[i]) {
            queue<int> tmp;
            t++;
            group[i] = 1;
            tmp.push(i);
            while (!tmp.empty()) {
                int cur = tmp.front();
                tmp.pop();
                for (int j = 1; j <= n; j++)
                    if (!group[j] && (tree[j] == cur || tree[cur] == j)) {
                        grnoup[j] = 1;
                        tmp.push(j);
                    }
            }
        }
    }
    printf("%d", t);
}
