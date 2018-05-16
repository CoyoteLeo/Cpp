#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int num[n], sum = 0;
    for (int i = 0; i < n; i++) 
        scanf("%d", &num[i]);
    sort(num, num + n);
    for (int i = 0; i < m;i++){
        if(num[i]>=0)
            break;
        sum += num[i];
    }
    printf("%d", abs(sum));
    return 0;
}
