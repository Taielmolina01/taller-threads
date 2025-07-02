#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../common_src/board_parser.h"
#include "../common_src/cell_parser.h"
#include "../common_src/common_protocol.h"
#include "../common_src/message.h"
#include "../common_src/socket.h"

#include "game.h"
#include "game_dto.h"
#include "server_protocol_parser.h"
#define CODE_CREATE_GAME 0x6E
#define CODE_JOIN_GAME 0x6A
#define CODE_LIST_GAMES 0x6C
#define CODE_MAKE_PLAY 0x70

class ServerProtocol: public CommonProtocol {
private:
    std::unordered_map<uint8_t, CommandType> codeToCommands;
    std::unordered_map<CommandType, std::function<MessageFromClient()>> commandsManagers;
    CellParser cellParser;
    ServerProtocolParser protocolParser;

    MessageFromClient receiveCreateGameRequest();
    MessageFromClient receiveJoinGameRequest();
    MessageFromClient receiveListGamesRequest();
    MessageFromClient receiveMakePlayRequest();
    void sendBoard(const MessageFromServer& msg);
    void sendListGames(const MessageFromServer& msg);

public:
    explicit ServerProtocol(Socket&& socket);
    void SendMessage(const MessageFromServer& msg);
    MessageFromClient ReceiveCommand();
    void kill();
    ~ServerProtocol();
};

#endif
