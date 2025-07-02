#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "../common_src/message.h"

#include "game_status.h"

#define NOT_OCUPPED " "
#define PLAYER_1_MARK "O"
#define PLAYER_2_MARK "X"

class Game {
private:
    std::vector<std::vector<std::string>> board;

    std::string actualPlayer;
    GameStatus status;

    void createEmptyBoard();
    bool cellIsEmpty(const int row, const int col) const;
    void checkWinnerInCols();
    void checkWinnerInRows();
    void checkWinnerInDiagonals();
    void checkTie();
    void updateStatus();
    void updateActualPlayer();

public:
    Game();
    void MakePlay(const int row, const int col);
    std::vector<std::vector<std::string>> GetBoard() const;
    GameStatus GetGameStatus() const;
    std::string GetActualPlayer() const;
};

#endif
