#ifndef GAME_MONITOR_H
#define GAME_MONITOR_H

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <vector>

#include "../common_src/final_messages.h"

#include "game.h"
#include "game_parser.h"
#include "server_protocol.h"

class ClientHandler;

class GameMonitor {
private:
    std::mutex mutex;
    std::vector<ClientHandler*> players;
    Game game;
    GameParser gameParser;
    CellParser cellParser;
    std::condition_variable gameIsReady;
    std::condition_variable isTurn;
    bool gameReady;

    void sendStatusGameWithWinner(const GameStatus& status, const GameDTO& dto);
    void sendStatusGameWithTie(const GameDTO& dto);
    void sendStatusGameWithUnfinishedGame(ClientHandler& client, const GameDTO& dto);

public:
    explicit GameMonitor(ClientHandler& client);

    Game GetGame() const;

    bool ConnectSecondPlayer(ClientHandler& client);
    void WaitSecondPlayer();
    void MakePlayGame(ClientHandler& client);

    bool isFinished();
};

#endif
