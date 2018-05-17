#pragma once
#include "grid.h"
#include <vector>

class Soduko
{
   public:
    Soduko(char a[9][9]);
    ~Soduko();
    bool solve();
    void set_result(char result[9][9]);

   private:
    int board[9][9];
    bool solve_grid(unsigned int index);

    bool canFillIn(int row, int column, int num);
    bool inRow(int num, int row);
    bool inColumn(int num, int column);
    bool inBlock(int num, int row, int column);

    bool findAvailable();
    void findAvailableForboard(bool rowRemain[9][10], bool columnRemain[9][10], bool blockRemain[9][10]);
    void findAvailableForGrid(bool rowRemain[9][10], bool columnRemain[9][10], bool blockRemain[9][10]);

    std::vector<Grid> unknown;
};
