/* 數論 */

#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int average = n / k;
    int ball[n + 1],color[k+1]={0};
    for (int i = 1; i <= n;i++){
        scanf("%d", &ball[i]);
        color[ball[i]]++;
    }
    sort(color + 1, color + k + 1);
    int sum = 0;
    for (int i = k; color[i]>average; i--) {
        // printf("%d\n", color[i]);
        sum += color[i] - average;
    }
    printf("%d", sum);
}