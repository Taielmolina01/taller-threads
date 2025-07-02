#include "game_parser.h"

GameDTO GameParser::GameToDTO(const Game& game) {
    return GameDTO{
            game.GetBoard(),
            game.GetGameStatus(),
    };
}
