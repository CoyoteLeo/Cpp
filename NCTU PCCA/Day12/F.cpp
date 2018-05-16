#include <bits/stdc++.h>
#define FORi(to) for (int i = 0; i < to; i++)
#define FORk(to) for (int k = 0; k < to; k++)
#define FORi1(to) for (int i = 1; i <= to; i++)
using namespace std;
typedef long long LL;
int in() {
    int x;
    scanf("%d", &x);
    return x;
}
int q[100005];
int aq[100005];
int main() {
    int t = in();
    while (t--) {
        int n = in();
        int finalPos = -1;
        FORi(n) {
            q[i] = in();
        }
        aq[0] = q[0];
        for (int i = 1; i < n; i++) {
            if (q[i] > 0) {
                finalPos = i;
            }
            if ((q[i] >= 0 && aq[i - 1] > 0) || (q[i] <= 0 && aq[i - 1] > 0)) {
                aq[i] = aq[i - 1] + q[i];
            } else {
                aq[i] = q[i];
            }
        }
        if ((q[0] > 0 && aq[n - 1] > 0) || (q[0] < 0 && aq[n - 1] > 0)) {
            aq[0] = aq[n - 1] + q[0];
            for (int i = 1; i < finalPos; i++) {
                if ((q[i] >= 0 && aq[i - 1] > 0) ||
                    (q[i] <= 0 && aq[i - 1] > 0)) {
                    aq[i] = aq[i - 1] + q[i];
                } else {
                    aq[i] = q[i];
                }
            }
        }
        if (finalPos == -1) {
            printf("0 0\n");
            continue;
        }
        int ans = -1, ansS, ansE;
        for (int i = 0; i < n; i++) {
            if (q[i] > 0) {
                int tans = 0, tansS = i, tansE;
                bool tag = true;
                while (aq[i] > 0 && i < n) {
                    i++;
                    tans++;
                    if (i == n && tag) {
                        i = 0;
                        n = finalPos;
                        tag = false;
                    }
                }
                if (tans > ans) {
                    ans = tans;
                    ansS = tansS;
                    ansE = i;
                }
            }
        }

        printf("%d %d\n", ansS + 1, ansE);
    }
}

