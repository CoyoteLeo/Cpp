#include "grid.h"
#include <vector>

Grid::Grid(int r, int c) : row(r), column(c)
{
}

bool Grid::operator<(Grid &m){
    return available.size() < m.available.size();
}