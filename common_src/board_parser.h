#ifndef BOARD_PARSER_H
#define BOARD_PARSER_H

#include <string>
#include <vector>

#define COLUMNS_INDICATOR "    1 . 2 . 3 ."
#define FIRST_ROW_INDICATOR "1"
#define SECOND_ROW_INDICATOR "2"
#define THIRD_ROW_INDICATOR "3"
#define BOARD_ROWS_DELIMITER "  +---+---+---+"
#define BOARD_INTERN_COLUMNS_DELIMTER " | "
#define BOARD_EXTERN_COLUMNS_DELIMITER " |"
#define BOARD_SIZE 128

class BoardParser {
public:
    std::string ParseDataToBoard(const std::vector<std::vector<std::string>>& board);
};

#endif
