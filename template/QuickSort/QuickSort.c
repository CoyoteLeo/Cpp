#include <bits/stdc++.h>

void swap(int *x,int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quicksort(int num[], int amount){
    if(amount<=1)
        return;
    swap(&num[0], &num[amount-1]);
    int left = 0;
    for (int i = 0; i < amount; i++)
    {
        if(num[i]<num[amount-1])
            swap(&num[i], &num[left++]);
    }
    swap(&num[amount-1], &num[left]);
    quicksort(&num[0], left);
    quicksort(&num[left+1], amount-left-1);
}

int main()
{
    int num[6]={5,2,8,7,4,3};
    quicksort(num, 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", num[i]);
}