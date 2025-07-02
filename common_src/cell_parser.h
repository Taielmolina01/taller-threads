#ifndef CELL_PARSER_H
#define CELL_PARSER_H

#include <vector>

#include "board_cell.h"

#define INDEX_ROW 0
#define INDEX_COL 1

class CellParser {
public:
    BoardCell ParseToCell(const int& row, const int& col);
    std::vector<int> ParseFromCell(const BoardCell& cell);
};

#endif
