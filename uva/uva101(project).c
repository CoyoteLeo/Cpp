#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(int **space, int a, int block_x, int block_y, int target_x, int target_y)
{
    space[target_x][target_y] = a;
    space[block_x][block_y] = -1;
}

void back(int **space, int x, int y)
{
    int i;
    for (i = y + 1; space[x][i] >= 0; i++)
    {
        space[space[x][i]][0] = space[x][i];
        space[x][i] = -1;
    }
}

int main()
{
    int amount, a, a_x, a_y, b, b_x, b_y, i, j;
    char command1[5], command2[5];
    while (scanf("%d", &amount) > 0 && amount >= 0)
    {
        int **space = (int **)malloc(amount * sizeof(int *) + amount * (amount + 1) * sizeof(int));
        int *sec_dim;
        for (i = 0, sec_dim = (int *)(space + amount); i < amount; i++, sec_dim += (amount + 1))
            space[i] = sec_dim;

        for (i = 0; i < amount; i++)
        {
            for (j = 0; j < amount + 1; j++)
                space[i][j] = -1;
            space[i][0] = i;
        }

        while (1)
        {
            scanf("%s", command1);
            if (strcmp(command1, "quit") == 0)
            {
                for (i = 0; i < amount; i++)
                {
                    printf("%d:", i);
                    for (j = 0; space[i][j] >= 0; j++)
                        printf(" %d", space[i][j]);
                    printf("\n");
                }
                break;
            }
            scanf("%d %s %d", &a, command2, &b);
            int a_flag, b_flag;
            for (i = 0, a_flag = 1, b_flag = 1; i < amount && (a_flag || b_flag); i++)
            {
                for (j = 0; space[i][j] >= 0; j++)
                {
                    if (a_flag && space[i][j] == a)
                    {
                        a_x = i;
                        a_y = j;
                    }
                    if (b_flag && space[i][j] == b)
                    {
                        b_x = i;
                        b_y = j;
                    }
                }
            }
            if (a_x == b_x)
                continue;
            if (strcmp(command1, "move") == 0)
            {
                if (strcmp(command2, "onto") == 0)
                {
                    back(space, a_x, a_y);
                    back(space, b_x, b_y);
                    move(space, a, a_x, a_y, b_x, b_y + 1);
                }
                else if (strcmp(command2, "over") == 0)
                {
                    back(space, a_x, a_y);
                    for (i = b_y + 1;; i++)
                    {
                        if (space[b_x][i] < 0)
                        {
                            move(space, a, a_x, a_y, b_x, i);
                            break;
                        }
                    }
                }
            }
            else if (strcmp(command1, "pile") == 0)
            {
                if (strcmp(command2, "onto") == 0)
                {
                    back(space, b_x, b_y);
                    for (i = 0; space[a_x][a_y + i] >= 0; i++)
                        move(space, space[a_x][a_y + i], a_x, a_y + i, b_x, b_y + 1 + i);
                }
                else if (strcmp(command2, "over") == 0)
                {
                    int flag;
                    for (i = 0, flag = 1; flag; i++)
                    {
                        if (space[b_x][b_y + 1 + i] < 0)
                        {
                            for (j = 0; space[a_x][a_y + j] >= 0; j++, i++)
                                move(space, space[a_x][a_y + j], a_x, a_y + j, b_x, b_y + 1 + i);
                            flag = 0;
                        }
                    }
                }
            }
        }
        free(space);
    }
    return 0;
}