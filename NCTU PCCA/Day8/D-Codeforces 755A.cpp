/* (數論) 
 * 輸入n，輸出一個m，使得n*m+1為一個非質數的數字*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;

int main() {
    int n;
    while (scanf("%d", &n) > 0) {
        if (n == 1) {
            printf("%d", 3);
        } else if (n == 2) {
            printf("%d", 4);
        } else if (n % 2 != 0) {
            printf("%d", 1);
        } else {
            printf("%d",n-2);
        }
    }
}
