#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>
#include <string>
#include <vector>

#include "../server_src/game_dto.h"

#include "board_cell.h"
#include "commands.h"

struct InternalMessage {
    uint8_t codeMessage;
    std::string line;
    std::vector<int> coordinate;
};

struct MessageFromServer {
    bool haveGame;
    GameDTO game;
    std::string extraMessage;
    std::vector<std::string> listGames;
};

struct ServerResponseMessage {
    std::string serverResponse;
};

struct MessageFromClient {
    CommandType commandType;
    std::string gameName;
    BoardCell cell;
};

#endif
