#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
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

int compareEdge(const void *e1, const void *e2)
{
    return ((Edge *)e1)->weight - ((Edge *)e2)->weight;
}

int main()
{
    int n, v, e, j, option, v1, v2, result, count, temp, choose_edge;
    bool vertexInMST[MAX1]; // 紀錄點是否已經在minimum spanning tree
    char ch;
    Edge edges[MAX2];
    scanf_d(n);
    for (int i = 0; i < n; ++i)
    {
        scanf_d(v);
        scanf_d(e);
        scanf_d(option);
        memset(vertexInMST, 0, MAX1);
        // 以0為起點
        vertexInMST[0] = true;
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
        qsort(edges, e, sizeof(Edge), compareEdge);
        result = 0;
        count = 1;
        // 重複迴圈直到所有點都在minimum spanning tree
        while (count < v)
        {
            temp = choose_edge = LONG_MAX;
            for (j = 0; j < e; ++j)
            {
                // 找尋與minimum spanning tree 距離最近的點
                if (((!vertexInMST[edges[j].start] && vertexInMST[edges[j].end]) ||
                     (vertexInMST[edges[j].start] && !vertexInMST[edges[j].end])) &&
                    temp > edges[j].weight)
                {
                    temp = edges[j].weight;
                    choose_edge = j;
                    break;
                }
            }
            // 將該點加入minimum spanning tree
            if (!vertexInMST[edges[choose_edge].end])
                vertexInMST[edges[choose_edge].end] = true;
            else
                vertexInMST[edges[choose_edge].start] = true;
            // 增加總和
            result += temp;
            ++count;
            if (option == 1)
            {
                print_d(edges[choose_edge].start);
                putchar(' ');
                print_d(edges[choose_edge].end);
                putchar('\n');
            }
        }
        printf("%d\n", result);
    }
    return 0;
}