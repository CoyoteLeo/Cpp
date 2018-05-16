#include <stdio.h>
#define MAX 1001
#define scanf_d(x)                                             \
    while ((ch = getchar()) == '\n' || ch == EOF || ch == ' ') \
    {                                                          \
    }                                                          \
    x = ch - 48;                                               \
    while ((ch = getchar()) != '\n' && ch != EOF && ch != ' ') \
        x = x * 10 + ch - 48;
        
int parent[MAX] = {0};
char ch;

int main()
{
    char cmd;
    int argv1, argv2, dep;
    while (scanf("%c", &cmd) != EOF && cmd != 'E')
    {
        switch (cmd)
        {
            case 'M':
                scanf_d(argv1);
                parent[argv1] = argv1;
                break;
            case 'G':
                scanf_d(argv1);
                scanf_d(argv2);
                parent[argv1] = argv2;
                break;
            case 'F':
                scanf_d(argv1);
                argv2 = argv1;
                dep = 0;
                while (parent[argv2] != argv2)
                {
                    ++dep;
                    argv2 = parent[argv2];
                }
                printf("%d %d\n", argv1, dep);
                break;
        }
    }
    return 0;
}