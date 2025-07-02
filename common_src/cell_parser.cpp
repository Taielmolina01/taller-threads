#include "cell_parser.h"

#include "board_cell.h"

BoardCell CellParser::ParseToCell(const int& row, const int& col) {
    return BoardCell((col - 1) * 3 + row - 1);
}

std::vector<int> CellParser::ParseFromCell(const BoardCell& cell) {
    return std::vector<int>() = {cell / 3, cell % 3};
}
