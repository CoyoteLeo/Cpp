#include <stdio.h>
#include <memory.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 900
#define scanf_d(x_)                                              \
    while (((ch = getchar()) == '\n' || ch == ' ') && ch != EOF) \
    {                                                            \
    }                                                            \
    x_ = ch - 48;                                                \
    while ((ch = getchar()) != EOF && ch != ' ' && ch != '\n')   \
        x_ = x_ * 10 + ch - 48;

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

int n, v, e, v1, v2, duplicate, result, i, j, k, status[MAX], count[MAX], vertices[MAX][MAX];
bool graph[MAX][MAX];

int dfs_visit(int start)
{
    status[start] = GRAY;
    for (int r = 0; r < count[start]; ++r)
        if (status[vertices[start][r]] == BLACK)
            return 0;
        else if (status[vertices[start][r]] == WHITE && !dfs_visit(vertices[start][r]))
            return 0;
    status[start] = BLACK;
    return 1;
}

int main()
{
    int temp;
    char ch;
    scanf_d(n);
    for (i = 0; i < n; ++i)
    {
        duplicate = 0;
        memset(vertices, 0, MAX * MAX * 4);
        memset(count, 0, MAX * 4);
        memset(graph, 0, MAX * MAX);
        scanf_d(v);
        scanf_d(e);
        for (j = 0; j < e; ++j)
        {
            scanf("%d", &v1);
            scanf_d(v2);
            if (duplicate)
                continue;
            else if (graph[v1][v2])
            {
                duplicate = 1;
                continue;
            }
            else
                vertices[v1][count[v1]++] = v2;
        }
        print_d(i + 1);
        putchar(' ');
        if (duplicate)
        {
            putchar('N');
            putchar('O');
            putchar('\n');
            continue;
        }
        result = 1;
        for (k = 0; k < v; ++k)
        {
            memset(status, 0, MAX * 4);
            if (!dfs_visit(k))
            {
                result = 0;
                break;
            }
        }
        if (result)
        {
            putchar('Y');
            putchar('E');
            putchar('S');
        }
        else
        {
            putchar('N');
            putchar('O');
        }
        putchar('\n');
    }
    return 0;
}