#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 5;
int sum[4 * maxn];

// i節點收集子節點的統計結果
void PushUp(int i) {
    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}
//遞歸建立線段樹
void build(int i, int l, int r) {
    if (l == r) {
        scanf("%d", &sum[i]);
        return;
    }
    int m = (l + r) / 2;
    build(i << 1, l, m);
    build(i << 1 | 1, m + 1, r);
    PushUp(i);  //收集子節點的結果
    //要時刻記住維護節點統計信息的正確性!!
}
//在當前區間[l,r]內查詢區間[ql,qr]間的目標值
//且能執行這個函數的前提是：[l,r]與[ql,qr]的交集不為空
//其實本函數返回的結果也是 它們交集的目標值
int query(int ql, int qr, int i, int l, int r) {
    if (ql <= l && qr >= r)
        return sum[i];
    int m = (l + r) / 2;
    int ans = 0;
    if (ql <= m)
        ans += query(ql, qr, i * 2, l, m);
    if (qr > m)  //特別注意此處，不是else!!!!!
        ans += query(ql, qr, i * 2 + 1, m + 1, r);
    return ans;
}
// update這個函數就有點定制的意味了
//本題是單點更新，所以實在區間[l,r]內使得第id數的值+val
//如果是區間更新，可以將函數的id參數變為ql,qr
void update(int id, int val, int i, int l, int r) {
    if (l == r) {
        sum[i] += val;
        return;
    }
    int m = (l + r) / 2;
    if (id <= m)
        update(id, val, i << 1, l, m);
    else
        update(id, val, i << 1 | 1, m + 1, r);
    PushUp(i);  //要時刻記住維護節點統計信息的正確性!!
}
int main() {
    int T, n, kase = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        build(1, 1, n);
        char str[10];
        int x, y;
        printf("Case %d:\n", i + 1);
        while (scanf("%s", str) > 0) {
            if (str[0] == 'E')
                break;
            scanf("%d %d", &x, &y);
            if (str[0] == 'A')
                update(x, y, 1, 1, n);
            else if (str[0] == 'S')
                update(x, -1 * y, 1, 1, n);
            else if (str[0] == 'Q')
                printf("%d\n", query(x, y, 1, 1, n));
        }
    }
    return 0;
}