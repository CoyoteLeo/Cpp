#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const string fileName = "words.txt";

bool findWord(string board[4], bool usage[4][4], char *word, int len, int x, int y)
{
    if (len == 0)
        return true;
    char now = word[0];
    bool find = false;
    for (int i = x - 1; i < x + 2 && !find; i++)
    {
        for (int j = y - 1; j < y + 2 && !find; j++)
        {
            if (i > -1 && i < 4 && j > -1 && j < 4 && board[i][j] == now && !usage[i][j])
            {
                usage[i][j] = true;
                find = findWord(board, usage, word + 1, len - 1, i, j);
                if (!find)
                    usage[i][j] = false;
            }
        }
    }
    return find;
}

int main()
{
    char temp[16];
    string board[4];
    bool usage[4][4];
    bool result;
    for (int i = 0; i < 4; i++)
        cin >> board[i];

    ifstream in(fileName);
    while (in >> temp)
    {
        result = false;
        for (int i = 0; i < 4 && !result; i++)
        {
            for (int j = 0; j < 4 && !result; j++)
            {
                if (board[i][j] == temp[0])
                {
                    memset(usage, 0, 16);
                    usage[i][j] = true;
                    result = findWord(board, usage, temp + 1, strlen(temp) - 1, i, j);
                    if (!result)
                        usage[i][j] = false;
                }
            }
        }
        if (result)
            cout << string(temp) << endl;
    }
    in.close();
    system("pause");
    return 0;
}