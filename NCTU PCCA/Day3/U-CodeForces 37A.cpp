#include <bits/stdc++.h>
using namespace std;

int main() {
    int bar[1000 + 1]={0}, amount;
    scanf("%d", &amount);
    for (int i = 0, len; i < amount; i++) {
        scanf("%d", &len);
        bar[len]++;
    }
    int tallest=0, count = 0;
    for (int i = 1; i < 1000 + 1;i++){
        tallest = max(tallest, bar[i]);
        if(bar[i]!=0)
            count++;
    }
    printf("%d %d", tallest, count);
}