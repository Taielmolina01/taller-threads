#include "client_parser.h"

#include <string>
#include <vector>

#include "../common_src/cell_parser.h"

ClientParser::ClientParser() {
    this->commandsMap = {{CREATE_GAME_KEYWORD, CommandType::CREATE_GAME},
                         {LIST_GAMES_KEYWORD, CommandType::LIST_GAMES},
                         {JOIN_GAME_KEYWORD, CommandType::JOIN_GAME},
                         {PLAY_GAME_KEYWORD, CommandType::MAKE_PLAY}};
    parsersMap[CommandType::CREATE_GAME] = [this](const std::vector<std::string>& tokens) {
        return parseCreateGameRequest(tokens);
    };
    parsersMap[CommandType::LIST_GAMES] = [this](const std::vector<std::string>& tokens) {
        return parseListGamesRequest(tokens);
    };
    parsersMap[CommandType::JOIN_GAME] = [this](const std::vector<std::string>& tokens) {
        return parseJoinGameRequest(tokens);
    };
    parsersMap[CommandType::MAKE_PLAY] = [this](const std::vector<std::string>& tokens) {
        return makePlayGameRequest(tokens);
    };
}

MessageFromClient ClientParser::ParseRequest(const std::string& request) {
    std::vector<std::string> splitted = splitter.Split(request, ' ');
    CommandType command = this->commandsMap.find(splitted[INDEX_REQUEST_TYPE_KEYWORD])->second;
    return this->parsersMap.find(command)->second(splitted);
}

MessageFromClient ClientParser::parseCreateGameRequest(const std::vector<std::string>& tokens) {
    return MessageFromClient{CommandType::CREATE_GAME, tokens[INDEX_GAME_NAME_IN_CREATE_REQUEST]};
}

MessageFromClient ClientParser::parseListGamesRequest(const std::vector<std::string>& tokens) {
    return MessageFromClient{
            CommandType::LIST_GAMES,
    };
}

MessageFromClient ClientParser::parseJoinGameRequest(const std::vector<std::string>& tokens) {
    return MessageFromClient{CommandType::JOIN_GAME, tokens[INDEX_GAME_NAME_IN_JOIN_REQUEST]};
}

MessageFromClient ClientParser::makePlayGameRequest(const std::vector<std::string>& tokens) {
    return MessageFromClient{
            CommandType::MAKE_PLAY, "",
            this->cellParser.ParseToCell(std::stoi(tokens[INDEX_ROW_IN_PLAY_REQUEST]),
                                         std::stoi(tokens[INDEX_COL_IN_PLAY_REQUEST]))};
}
