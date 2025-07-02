#ifndef GAME_DTO_H
#define GAME_DTO_H

#include <string>
#include <vector>

#include "game_status.h"

struct GameDTO {
    std::vector<std::vector<std::string>> board;
    GameStatus status;
};

#endif
