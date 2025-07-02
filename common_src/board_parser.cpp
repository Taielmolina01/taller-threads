#include "board_parser.h"

#include <sstream>

std::string BoardParser::ParseDataToBoard(const std::vector<std::vector<std::string>>& board) {
    std::stringstream ss;
    ss << COLUMNS_INDICATOR << "\n";
    ss << BOARD_ROWS_DELIMITER << "\n";
    ss << FIRST_ROW_INDICATOR << BOARD_EXTERN_COLUMNS_DELIMITER << " " << board[0][0]
       << BOARD_INTERN_COLUMNS_DELIMTER << board[0][1] << BOARD_INTERN_COLUMNS_DELIMTER
       << board[0][2] << BOARD_EXTERN_COLUMNS_DELIMITER << "\n";
    ss << BOARD_ROWS_DELIMITER << "\n";
    ss << SECOND_ROW_INDICATOR << BOARD_EXTERN_COLUMNS_DELIMITER << " " << board[1][0]
       << BOARD_INTERN_COLUMNS_DELIMTER << board[1][1] << BOARD_INTERN_COLUMNS_DELIMTER
       << board[1][2] << BOARD_EXTERN_COLUMNS_DELIMITER << "\n";
    ss << BOARD_ROWS_DELIMITER << "\n";
    ss << THIRD_ROW_INDICATOR << BOARD_EXTERN_COLUMNS_DELIMITER << " " << board[2][0]
       << BOARD_INTERN_COLUMNS_DELIMTER << board[2][1] << BOARD_INTERN_COLUMNS_DELIMTER
       << board[2][2] << BOARD_EXTERN_COLUMNS_DELIMITER << "\n";
    ss << BOARD_ROWS_DELIMITER << "\n";
    return ss.str();
}
