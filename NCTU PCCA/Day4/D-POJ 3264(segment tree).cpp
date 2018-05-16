#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 7;

typedef struct data {
    int tallest;
    int shortest;
} data;

data cows[4 * maxn];
void init(int n) {
    n <<= 2;
    for (int i = 0; i < n; i++) {
        cows[i].tallest = 1 << 31 - 1;
        cows[i].shortest = 1 << 31;
    }
}
// i節點收集子節點的統計結果
void PushUp(int i) {
    cows[i].tallest = max(cows[(i << 1)].tallest, cows[(i << 1 | 1)].tallest);
    cows[i].shortest =
        min(cows[(i << 1)].shortest, cows[(i << 1 | 1)].shortest);
}
//遞歸建立線段樹
void build(int i, int l, int r) {
    if (l == r) {
        int height;
        scanf("%d", &height);
        cows[i].shortest = cows[i].tallest = height;
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
int queryTallest(int ql, int qr, int i, int l, int r) {
    if (ql <= l && qr >= r)
        return cows[i].tallest;
    int m = (l + r) / 2;
    int ans = 0;
    if (ql <= m)
        ans = max(ans, queryTallest(ql, qr, i * 2, l, m));
    if (qr > m)  //特別注意此處，不是else!!!!!
        ans = max(ans, queryTallest(ql, qr, i * 2 + 1, m + 1, r));
    return ans;
}
int queryShortest(int ql, int qr, int i, int l, int r) {
    if (ql <= l && qr >= r)
        return cows[i].shortest;
    int m = (l + r) / 2;
    int ans = (1 << 31 - 1);
    if (ql <= m)
        ans = min(ans, queryShortest(ql, qr, i * 2, l, m));
    if (qr > m)  //特別注意此處，不是else!!!!!
        ans = min(ans, queryShortest(ql, qr, i * 2 + 1, m + 1, r));
    return ans;
}
// // update這個函數就有點定制的意味了
// //本題是單點更新，所以實在區間[l,r]內使得第id數的值+val
// //如果是區間更新，可以將函數的id參數變為ql,qr
// void update(int id, int val, int i, int l, int r) {
//     if (l == r) {
//         sum[i] += val;
//         return;
//     }
//     int m = (l + r) / 2;
//     if (id <= m)
//         update(id, val, i << 1, l, m);
//     else
//         update(id, val, i << 1 | 1, m + 1, r);
//     PushUp(i);  //要時刻記住維護節點統計信息的正確性!!
// }

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    init(N);
    build(1, 1, N);
    for (int i = 0, x, y; i < Q; i++) {
        scanf("%d %d", &x, &y);
        int tallest = queryTallest(x, y, 1, 1, N);
        int shortest = queryShortest(x, y, 1, 1, N);
        // printf("------------%d %d\n", tallest, shortest);
        printf("%d\n", tallest - shortest);
    }
    return 0;
}