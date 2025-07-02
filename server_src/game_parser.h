#ifndef GAME_PARSER_H
#define GAME_PARSER_H

#include <string>
#include <vector>

#include "game.h"
#include "game_dto.h"
#include "game_status.h"

class GameParser {
public:
    GameDTO GameToDTO(const Game& game);
};

#endif
