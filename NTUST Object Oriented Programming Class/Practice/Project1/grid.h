#pragma once
#include<vector>

class Grid
{
   public:
    friend class Soduko;
    Grid(int r, int c);
    bool operator<(Grid &m);

   private:
    int row;
    int column;
    std::vector<int> available;
};