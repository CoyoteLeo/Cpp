#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int no;
    int side[10];
    int pre;
    int length;
} Box;

int amount, dimension;

int lexico_less(const void* a, const void* b) {
    Box *box1 = (Box*)a, *box2 = (Box*)b;
    for (int i = 0; i < dimension; ++i) {
        if (box1->side[i] == box2->side[i])
            continue;
        return box1->side[i] - box2->side[i];
    }
    return 0;
}

int compareside(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void trace(Box box[],int no, int flag) {
    int now = -1;
    for (int i = 0; i < amount; i++) {
        if (box[i].no == no) {
            now = i;
            break;
        }
    }
    if (box[now].pre != -1)
        trace(box,box[now].pre, 1);
    if (flag)
        printf("%d ", box[now].no);
    else
        printf("%d", box[now].no);
}

int main() {
    Box box[30] = {0};
    while (scanf(" %d %d", &amount, &dimension) > 0) {
        for (int i = 0; i < 30;i++){
        
        }
            for (int i = 0; i < amount; i++) {
                for (int j = 0; j < dimension; j++)
                    scanf(" %d", &box[i].side[j]);
                box[i].no = i + 1;
                box[i].length = 1;
                box[i].pre = -1;
                // quicksort the sides of the box
                qsort(&box[i].side[0], dimension, sizeof(int), compareside);
            }
        // quicksort the volumn of the boxes
        qsort(box, amount, sizeof(Box), lexico_less);
        for (int i = 0; i < amount; ++i)
            for (int j = 0; j < i; ++j) {
                // judge box[i] is bigger than the boxes which are before it or
                // not
                int flag = 1, counter = 0;
                for (int d = 0; d < dimension; d++) {
                    if (box[i].side[d] <= box[j].side[d]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    if (box[j].length + 1 > box[i].length) {
                        box[i].length = box[j].length + 1;
                        box[i].pre = box[j].no;
                    }
                }
            }
        int max = 0;
        Box now_box = {0};
        for (int i = 0; i < amount; i++) {
            if (box[i].length > now_box.length) {
                now_box.length = box[i].length;
                now_box = box[i];
            }
        }
        printf("%d\n", now_box.length);
        trace(box,now_box.no, 0);
        puts("");
    }
    return 0;
}