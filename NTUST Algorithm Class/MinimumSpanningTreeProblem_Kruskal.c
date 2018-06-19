#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX1 1000
#define MAX2 10000
// 自定義輸入int
#define scanf_d(x_)                                              \
    while (((ch = getchar()) == '\n' || ch == ' ') && ch != EOF) \
    {                                                            \
    }                                                            \
    x_ = ch - 48;                                                \
    while ((ch = getchar()) != EOF && ch != ' ' && ch != '\n')   \
        x_ = x_ * 10 + ch - 48;
// 自定義輸入int
#define scanf_d2(x_, y_)                                         \
    while (((ch = getchar()) == '\n' || ch == ' ') && ch != EOF) \
    {                                                            \
    }                                                            \
    x_ = ch - 48;                                                \
    while ((ch = getchar()) != EOF && ch != ' ' && ch != '\n')   \
        x_ = x_ * 10 + ch - 48;                                  \
    y_ = x_;
// 自定義輸出int
#define print_d(y)                  \
    temp = y;                       \
    if (temp >= 100)                \
    {                               \
        putchar((temp / 100) + 48); \
        temp %= 100;                \
    }                               \
    if (temp >= 10)                 \
    {                               \
        putchar((temp / 10) + 48);  \
        temp %= 10;                 \
    }                               \
    putchar(temp + 48);

typedef struct Edge
{
    int start, end, weight;
} Edge;

// 比較邊的權重
int compareEdge(const void *e1, const void *e2)
{
    return ((Edge *)e1)->weight - ((Edge *)e2)->weight;
}

int main()
{
    int n, v, e, j, option, v1, v2, result, count, temp;
    int vertexBelongSet[MAX1]; // 紀錄每個點現在屬於哪個集合
    char ch;
    Edge edges[MAX2]; // 紀錄所有的邊
    scanf_d(n);
    for (int i = 0; i < n; ++i)
    {
        scanf_d(v);
        scanf_d(e);
        scanf_d(option);
        // 將所有的點分別歸到不同的集合
        for (j = 0; j < v; ++j)
            vertexBelongSet[j] = j;
        for (j = 0; j < e; ++j)
        {
            scanf_d2(edges[j].start, v1);
            scanf_d2(edges[j].end, v2);
            scanf_d(edges[j].weight);
            // 當讀入的邊起點比終點大時 進行對調的動作
            if (v1 > v2)
            {
                temp = edges[j].start;
                edges[j].start = edges[j].end;
                edges[j].end = temp;
            }
        }
        // 對所有的邊做排序
        qsort(edges, e, sizeof(Edge), compareEdge);
        --v;
        // 重複迴圈 直到做了v-1次(找出v-1條light edge)
        for (j = count = result = 0; count < v; ++j)
        {
            v1 = edges[j].start;
            v2 = edges[j].end;
            if (vertexBelongSet[v1] != vertexBelongSet[v2])  // 邊的兩點是不同集合
            {
                vertexBelongSet[v2] = vertexBelongSet[v1];  // 將兩個集合union
                result += edges[j].weight;  //將此邊的權重加進總和
                ++count;  // 找到一條light edge
                if (option == 1)  //當option是1時候印出邊的起點跟終點
                {
                    print_d(v1);
                    putchar(' ');
                    print_d(v2);
                    putchar('\n');
                }
            }
        }
        printf("%d\n", result);
    }
    return 0;
}