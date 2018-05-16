#define LONG_MIN -2147483647
#include <stdio.h>
using namespace std;

typedef struct Ans
{
    int leftMax;
    int rightMax;
    int value;
} Ans;

Ans getSubArrayMax(int a[], int amount)
{
    int maxSum = LONG_MIN, sum = 0, left = 0, right = 0;
    Ans ans = {0, 0, LONG_MIN};
    for (int i = 0; i < amount; i++)
    {
        sum = sum + a[i];
        if (maxSum < sum)
        {
            right = i;
            maxSum = sum;
        }

        if (sum < 0)
        {
            if (ans.value < maxSum)
                ans = {left, right, maxSum};
            left = i + 1;
            sum = 0;
        }
    }
    if (ans.value < maxSum)
        ans = {left, right, maxSum};
    return ans;
}

int main()
{
    int amount;
    while (scanf("%d", &amount) != EOF)
    {
        int num[amount];
        for (int i = 0; i < amount; i++)
            scanf("%d", &num[i]);
        Ans ans = getSubArrayMax(num, amount);
        printf("%d %d %d\n", ans.leftMax, ans.rightMax, ans.value);
    }
    return 0;
}