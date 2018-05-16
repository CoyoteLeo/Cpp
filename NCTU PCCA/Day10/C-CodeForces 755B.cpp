/* 數論 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, duplicate = 0;
    scanf("%d%d", &n, &m);
    char a[1005][505], b[1005][505], s[505];
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        for (int j = 0; j < n; j++)
            if (strcmp(s, a[j]) == 0) {
                duplicate++;
                break;
            }
    }
    n -= duplicate;
    m -= duplicate;
    if(duplicate%2!=0){
        if(m>n)
            printf("NO");
            else
                printf("YES");
    }else{
        if (m >= n)
            printf("NO");
        else
            printf("YES");
    }
    return 0;
}