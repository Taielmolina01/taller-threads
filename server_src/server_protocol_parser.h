#ifndef SERVER_PROTOCOL_PARSER_H
#define SERVER_PROTOCOL_PARSER_H

#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

#include "../common_src/board_parser.h"
#include "../common_src/message.h"
#define LIST_GAMES_TITLE "Partidas:\n"
#define MARKER_LIST_ITEM " - "

class ServerProtocolParser {
private:
    BoardParser boardParser;

public:
    std::vector<uint8_t> ParseByteToRowAndCol(const uint8_t& byte);
    std::string ParseListToString(const std::vector<std::string>& listGames);
    std::string ParseBoardResponse(const MessageFromServer& msg);
};

#endif
