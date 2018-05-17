#include <stdio.h>

int main() {
    int a[3], b[3], c[3];
    while (scanf(" %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &b[0],
                 &b[1], &b[2], &c[0], &c[1], &c[2]) > 0) {
        int no_move = a[0] + b[2] + c[1], flag = 0, tmp;
        int total =
            a[0] + a[1] + a[2] + b[0] + b[1] + b[2] + c[0] + c[1] + c[2];
        if ((tmp = a[0] + b[1] + c[2]) && no_move < tmp) {
            flag = 1;
            no_move = tmp;
        }
        if ((tmp = a[2] + b[0] + c[1]) && no_move < tmp) {
            flag = 4;
            no_move = tmp;
        }
        if ((tmp = a[2] + b[1] + c[0]) && no_move < tmp) {
            flag = 5;
            no_move = tmp;
        }
        if ((tmp = a[1] + b[0] + c[2]) && no_move < tmp) {
            flag = 2;
            no_move = tmp;
        }
        if ((tmp = a[1] + b[2] + c[0]) && no_move < tmp) {
            flag = 3;
            no_move = tmp;
        }
        if (flag == 0) {
            printf("BCG %d\n", total - no_move);
        } else if (flag == 1) {
            printf("BGC %d\n", total - no_move);
        } else if (flag == 2) {
            printf("GBC %d\n", total - no_move);
        } else if (flag == 3) {
            printf("GCB %d\n", total - no_move);
        } else if (flag == 4) {
            printf("CBG %d\n", total - no_move);
        } else if (flag == 5)
            printf("CGB %d\n", total - no_move);
    }
}