#include "game.h"

Game::Game() {
    this->createEmptyBoard();
    this->status.haveTie = false;
    this->status.haveWinner = false;
    this->status.winner = "";
    this->actualPlayer = PLAYER_1_MARK;
}

void Game::createEmptyBoard() {
    for (int i = 0; i < 3; i++) {
        std::vector<std::string> row;
        for (int j = 0; j < 3; j++) {
            row.push_back(NOT_OCUPPED);
        }
        this->board.push_back(row);
    }
}

void Game::checkWinnerInCols() {
    for (int i = 0; i < 3; i++) {
        if (!this->cellIsEmpty(0, i) && this->board[0][i] == this->board[1][i] &&
            this->board[0][i] == this->board[2][i]) {
            this->status.haveWinner = true;
            this->status.winner = this->GetActualPlayer();
        }
    }
}

void Game::checkWinnerInRows() {
    for (int i = 0; i < 3; i++) {
        if (!this->cellIsEmpty(i, 0) && this->board[i][0] == this->board[i][1] &&
            this->board[i][0] == this->board[i][2]) {
            this->status.haveWinner = true;
            this->status.winner = this->GetActualPlayer();
        }
    }
}

void Game::checkWinnerInDiagonals() {
    bool topLeftToDownRight = !this->cellIsEmpty(0, 0) && this->board[0][0] == this->board[1][1] &&
                              this->board[0][0] == this->board[2][2];

    bool downLeftToTopRight = !this->cellIsEmpty(2, 0) && this->board[2][0] == this->board[1][1] &&
                              this->board[2][0] == this->board[0][2];

    if (topLeftToDownRight || downLeftToTopRight) {
        this->status.haveWinner = true;
        this->status.winner = this->GetActualPlayer();
    }
}

void Game::checkTie() {
    int countOfMarks = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!this->cellIsEmpty(i, j)) {
                countOfMarks++;
            }
        }
    }
    if (!this->status.haveWinner && countOfMarks == 9) {
        this->status.haveTie = true;
    }
}

void Game::updateStatus() {
    this->checkWinnerInCols();
    this->checkWinnerInRows();
    this->checkWinnerInDiagonals();
    this->checkTie();
}

void Game::MakePlay(const int row, const int col) {
    if (this->cellIsEmpty(row, col)) {
        this->board[row][col] = this->GetActualPlayer();
    }
    this->updateStatus();
    this->updateActualPlayer();
}

void Game::updateActualPlayer() {
    this->actualPlayer = (this->GetActualPlayer() == PLAYER_1_MARK ? PLAYER_2_MARK : PLAYER_1_MARK);
}

std::vector<std::vector<std::string>> Game::GetBoard() const { return this->board; }

GameStatus Game::GetGameStatus() const { return this->status; }

bool Game::cellIsEmpty(const int row, const int col) const {
    return this->board[row][col] == NOT_OCUPPED;
}

std::string Game::GetActualPlayer() const { return this->actualPlayer; }
