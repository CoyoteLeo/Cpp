#define LONG_MIN -2147483647
#include <stdio.h>

int i, amount, num, maxSum, sum, left, right, tempLeft;
int main()
{
    while (scanf("%d", &amount) != EOF)
    {
        maxSum = LONG_MIN;
        scanf("%d", &sum);
        tempLeft = 0;
        for (i = 1; i < amount; ++i)
        {
            scanf("%d", &num);
            sum = sum + num;
            if (maxSum < sum)
            {
                right = i;
                left = tempLeft;
                maxSum = sum;
            }
            if (sum < 0)
            {
                tempLeft = i + 1;
                sum = 0;
            }
        }
        printf("%d %d %d\n", left, right, maxSum);
    }
    return 0;
}