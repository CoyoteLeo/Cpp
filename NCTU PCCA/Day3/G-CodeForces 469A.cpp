#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q;
    scanf("%d", &n);
    int num[n] = {0};
    scanf("%d", &p);
    for (int i = 0, level; i < p; i++) {
        scanf("%d", &level);
        num[level - 1]++;
    }
    scanf("%d", &q);
    for (int i = 0, level; i < q; i++) {
        scanf("%d", &level);
        num[level - 1]++;
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (num[i] == 0) {
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("I become the guy.");
    }else{
        printf("Oh, my keyboard!");
    }
    return 0;
}
