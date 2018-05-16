#include <stdio.h>
#define LONG_MIN -2147483647

int leftSum, rightSum, maxLeft, maxRight, sum, i;

typedef struct Ans{
    int leftMax, rightMax, value;
} Ans;

Ans ans;

Ans findMaxCrossSubArray(int num[], int low, int mid, int high){
    maxLeft = mid;
    maxRight = mid;

    leftSum = LONG_MIN;
    sum = 0;
    low = low - 1;
    for (i = mid; i > low; --i){
        sum = sum + num[i];
        if (sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    rightSum = LONG_MIN;
    sum = 0;
    high = high + 1;
    for (i = mid + 1; i < high; ++i){
        sum = sum + num[i];
        if (sum > rightSum){
            rightSum = sum;
            maxRight = i;
        }
    }
    Ans ans = {maxLeft, maxRight, leftSum + rightSum};
    return ans;
}

Ans findMaxSubArray(int num[], int low, int high){
    if (high == low){
        ans.leftMax = low;
        ans.rightMax = high;
        ans.value = num[low];
        return ans;
    }
    else{
        int mid = (low + high) / 2;
        Ans leftSum = findMaxSubArray(num, low, mid), 
            rightSum = findMaxSubArray(num, mid + 1, high),
            crossSum = findMaxCrossSubArray(num, low, mid, high);
        if (!(leftSum.value < rightSum.value || leftSum.value < crossSum.value))
            return leftSum;
        else if (!(rightSum.value < leftSum.value || rightSum.value < crossSum.value))
            return rightSum;
        else
            return crossSum;
    }
}
int main()
{
    int amount, num[100000];
    while (scanf("%d", &amount) != EOF){
        for (i = 0; i < amount; ++i)
            scanf("%d", &num[i]);
        Ans ans = findMaxSubArray(num, 0, amount - 1);
        printf("%d %d %d\n", ans.leftMax, ans.rightMax, ans.value);
    }
    return 0;
}