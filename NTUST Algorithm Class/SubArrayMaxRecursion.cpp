#include <climits>
#include <stdio.h>
using namespace std;

typedef struct Ans
{
    int leftMax;
    int rightMax;
    int value;
} Ans;

Ans findMaxCrossSubArray(int num[], int low, int mid, int high)
{
    int leftSum = LONG_MIN, rightSum = LONG_MIN, maxLeft = mid, maxRight = mid, sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += num[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += num[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }
    Ans ans = {maxLeft, maxRight, leftSum + rightSum};
    return ans;
}

Ans findMaxSubArray(int num[], int low, int high)
{
    if (high == low)
    {
        Ans ans = {low, high, num[low]};
        return ans;
    }
    else
    {
        int mid = (low + high) / 2;
        Ans leftSum, rightSum, crossSum;
        leftSum = findMaxSubArray(num, low, mid);
        rightSum = findMaxSubArray(num, mid + 1, high);
        crossSum = findMaxCrossSubArray(num, low, mid, high);
        if (leftSum.value >= rightSum.value && leftSum.value >= crossSum.value)
            return leftSum;
        else if (rightSum.value >= leftSum.value && rightSum.value >= crossSum.value)
            return rightSum;
        else
            return crossSum;
    }
}
int main()
{
    int amount;
    while (scanf("%d", &amount) != EOF)
    {
        int num[amount];
        for (int i = 0; i < amount; i++)
            scanf("%d", &num[i]);
        Ans ans = findMaxSubArray(num, 0, amount - 1);
        printf("%d %d %d\n", ans.leftMax, ans.rightMax, ans.value);
    }
    return 0;
}