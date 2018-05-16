#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX 1001
// 自定義 scan int
#define scanf_d(x)                                             \
    while ((ch = getchar()) == '\n' || ch == EOF || ch == ' ') \
    {                                                          \
    }                                                          \
    x = ch - 48;                                               \
    while ((ch = getchar()) != '\n' && ch != EOF && ch != ' ') \
        x = x * 10 + ch - 48;

int i, j, n, amount, temp, p, q, max, max_index, result[MAX], result_index;
int activity[MAX][6];  // activity array
// 0:start 1:finish 2:weight 3:total 4:pre 5:id
char ch;

int compare_activity(const void *m, const void *n)
{
    return (((int *)m)[1] - ((int *)n)[1]);
}

int compare_int(const void *m, const void *n)
{
    return (*(int *)m - *(int *)n);
}

int main()
{
    scanf_d(n);  // 輸入測資數量
    for (i = 0; i < n; i++)
    {
        scanf_d(amount);  // 輸入活動數量
        result_index = 0;
        max = max_index = 0;
        for (j = 0; j < amount; j++)
        {  // 輸入活動內容
            scanf_d(activity[j][5]);
            scanf_d(activity[j][0]);
            scanf_d(activity[j][1]);
            scanf_d(activity[j][2]);
            activity[j][3] = activity[j][2];
        };
        // 以結束時間排序活動
        qsort(activity, amount, 24, compare_activity);
        // 開始建立 dp 表
        for (p = 0; p < amount; p++)
        {
            activity[p][4] = p;
            for (q = 0; q < p; q++)
            {
                // 找出可接在 p 之前的活動
                if (activity[q][1] <= activity[p][0])
                {
                    temp = activity[q][3] + activity[p][2];
                    // 更新 p 的總和
                    if (temp > activity[p][3])
                    {
                        activity[p][3] = temp;

                        activity[p][4] = q;
                    }
                }
            }
            // 更新當前最大值及索引
            if (activity[p][3] > max)
            {
                max = activity[p][3];
                max_index = p;
            }
        }
        printf("%d", activity[max_index][3]);  // 印出最大值
        putchar('\n');
        // 建立答案的序列
        result[result_index++] = activity[max_index][5];
        // 從最後往前推找出活動序列，當活動的前一個是自己時表示自己就是第一個
        while (max_index != activity[max_index][4])
        {
            max_index = activity[max_index][4];
            result[result_index++] = activity[max_index][5];
        }
        // 依照 ID 排序結果
        qsort(result, result_index, sizeof(int), compare_int);
        // 列印出結果
        printf("%d", result[0]);
        for (p = 1; p < result_index; p++)
        {
            putchar(' ');
            printf("%d", result[p]);
        }
        putchar('\n');
    }
    return 0;
}