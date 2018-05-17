#include "Soduko.h"
#include "grid.h"
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

Soduko::Soduko(char q[9][9])
{
    memset(board, 0, 324);  // reset board
                            // set the board
    for (unsigned int i = 0; i < 9; i++)
    {
        for (unsigned int j = 0; j < 9; j++)
        {
            if (q[i][j] == 'n')
            {
                board[i][j] = 0;
                unknown.push_back(Grid(i, j));
            }
            else
            {
                board[i][j] = q[i][j] - 48;
            }
        }
    }
}

Soduko::~Soduko()
{
}

bool Soduko::solve()
{
    if (findAvailable())
    {
        sort(unknown.begin(), unknown.end());
        return solve_grid(0);
    }
    else
        return true;
}

bool Soduko::solve_grid(unsigned int index)
{
    for (unsigned int i = 0; i < unknown[index].available.size(); ++i)
    {
        int row = unknown[index].row;
        int column = unknown[index].column;
        int num = unknown[index].available[i];
        if (canFillIn(row, column, num))
        {
            board[unknown[index].row][unknown[index].column] = unknown[index].available[i];

            // solve all unknow grid -> success
            if (index + 1 > unknown.size() - 1)
                return true;

            // solve next unknown grid
            if (solve_grid(index + 1))
                return true;
            // this trial fail, so reset the grid
            board[unknown[index].row][unknown[index].column] = 0;
        }
    }
    // all available numbers test fail -> no solution
    return false;
}

void Soduko::set_result(char result[9][9])
{
    // set the result table
    for (unsigned int i = 0; i < 9; i++)
    {
        for (unsigned j = 0; j < 9; j++)
        {
            result[i][j] = board[i][j] + 48;
        }
    }
}

bool Soduko::canFillIn(int row, int column, int num)
{
    return (!inRow(num, row) && !inColumn(num, column) && !inBlock(num, row, column));
}

bool Soduko::inRow(int num, int row)
{
    for (unsigned int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return true;
    }
    return false;
}

bool Soduko::inColumn(int num, int column)
{
    for (unsigned int i = 0; i < 9; i++)
    {
        if (board[i][column] == num)
            return true;
    }
    return false;
}

bool Soduko::inBlock(int num, int row, int column)
{
    for (unsigned int i = row / 3 * 3, i_max = i + 3; i < i_max; i++)
    {                                                                         // row-row%3
        for (unsigned int j = column / 3 * 3, j_max = j + 3; j < j_max; j++)  // column-column%3
            if (board[i][j] == num)
                return true;
    }
    return false;
}

bool Soduko::findAvailable()
{
    bool rowRemain[9][10];
    bool columnRemain[9][10];
    bool blockRemain[9][10];
    memset(rowRemain, 1, 90);
    memset(columnRemain, 1, 90);
    memset(blockRemain, 1, 90);
    findAvailableForboard(rowRemain, columnRemain, blockRemain);
    findAvailableForGrid(rowRemain, columnRemain, blockRemain);
    return unknown.size() > 0;
}

void Soduko::findAvailableForboard(bool rowRemain[9][10], bool columnRemain[9][10], bool blockRemain[9][10])
{
    for (unsigned int i = 0; i < 9; i++)
    {
        for (unsigned int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)
            {
                rowRemain[i][board[i][j]] = false;
                columnRemain[j][board[i][j]] = false;
                blockRemain[i / 3 * 3 + j / 3][board[i][j]] = false;
            }
        }
    }
}

void Soduko::findAvailableForGrid(bool rowRemain[9][10], bool columnRemain[9][10], bool blockRemain[9][10])
{
    bool num[10];
    int row, column;
    for (unsigned int i = 0; i < unknown.size(); i++)
    {
        memset(num, 0, 10);
        row = unknown[i].row;
        column = unknown[i].column;
        for (int j = 1; j < 10; j++)
        {
            num[j] = (rowRemain[row][j] && columnRemain[column][j] && blockRemain[row / 3 * 3 + column / 3][j]);
            if (num[j])
            {
                unknown[i].available.push_back(j);
            }
        }
    }
}
