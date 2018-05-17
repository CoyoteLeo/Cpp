#include <iostream>
#include <fstream>
#include "soduko.h"
#define N 9
using namespace std;

const std::string FILE_NAME = "Question.txt";

void print(char a[N][N]);
int main()
{
    ifstream in(FILE_NAME);
    char q[9][9];
    if (!in.fail())
    {
        while (true)
        {
            for (unsigned int i = 0; i < 9; i++)
            {
                for (unsigned int j = 0; j < 9; j++)
                {
                    in >> q[i][j];
                }
            }

            if (in.eof())
                break;
            else
                cout << endl;

            Soduko s(q);
            if (s.solve())
            {
                s.set_result(q);
                print(q);
            }
            else
                cout << "No answer" << endl;
        }
    }
    else
    {
        cout << "Open File Error" << endl;
    }
    system("pause");
    return 0;
}

void print(char a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        printf(" ---------  ---------  ---------\n");
        if (i == 3 || i == 6)
            printf(" ---------  ---------  ---------\n");

        for (int j = 0; j < N; j++)
        {
            if (j == 3 || j == 6)
                printf("｜");
            printf("｜%c", a[i][j]);
        }
        printf("｜\n");
    }
    printf(" ---------  ---------  ---------\n");
}