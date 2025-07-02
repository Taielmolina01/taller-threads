#ifndef SERVER_MONITOR_H
#define SERVER_MONITOR_H

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "game.h"
#include "game_monitor.h"
#include "game_parser.h"

class ServerMonitor {
private:
    std::mutex mutex;
    std::map<std::string, GameMonitor> gameMonitors;
    GameParser gameParser;

public:
    bool CreateNewGame(const std::string& gameName, ClientHandler& client);
    std::vector<std::string> ListGames();
    bool JoinGame(const std::string& gameName, ClientHandler& client);
    void MakePlayGame(const std::string& gameName, ClientHandler& client);
    GameMonitor& GetGameMonitor(const std::string& gameName);
    void ManageEndGame(const std::string& gameName);
};

#endif
