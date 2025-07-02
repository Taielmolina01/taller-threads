#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include <string>

struct GameStatus {
    bool haveWinner;
    std::string winner;
    bool haveTie;
};

#endif
