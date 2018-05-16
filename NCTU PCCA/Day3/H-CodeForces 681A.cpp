#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[20];
        scanf("%s", s);
        int x, y;
        scanf("%d %d", &x, &y);
        if (y > x && x >= 2400)
            flag = 1;
    }
    if(flag){
        printf("YES");
    }else{
        printf("NO");
    }
}
