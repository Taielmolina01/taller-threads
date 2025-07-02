#include "game_monitor.h"

#include "client_handler.h"

GameMonitor::GameMonitor(ClientHandler& client): game(), gameReady(false) {
    players.push_back(&client);
}

bool GameMonitor::ConnectSecondPlayer(ClientHandler& client) {
    if (this->players.size() == 1) {
        this->players.push_back(&client);
        this->gameReady = true;
        this->gameIsReady.notify_all();
        return true;
    }
    return false;
}

void GameMonitor::WaitSecondPlayer() {
    std::unique_lock<std::mutex> lck(this->mutex);
    this->gameIsReady.wait(lck, [&]() { return this->gameReady; });
}

void GameMonitor::MakePlayGame(ClientHandler& client) {
    MessageFromClient msg = client.ReceivePlay();
    std::vector<int> coordinates = this->cellParser.ParseFromCell(msg.cell);

    this->game.MakePlay(coordinates[INDEX_ROW], coordinates[INDEX_COL]);
    GameStatus status = this->game.GetGameStatus();
    GameDTO dto = this->gameParser.GameToDTO(game);

    if (status.haveWinner) {
        this->sendStatusGameWithWinner(status, dto);
    } else if (status.haveTie) {
        this->sendStatusGameWithTie(dto);
    } else {
        this->sendStatusGameWithUnfinishedGame(client, dto);
    }
}

void GameMonitor::sendStatusGameWithWinner(const GameStatus& status, const GameDTO& dto) {
    ClientHandler* winner = status.winner == PLAYER_1_MARK ? this->players[0] : this->players[1];
    ClientHandler* loser = winner == this->players[0] ? this->players[1] : this->players[0];

    winner->SendStatusGame(MessageFromServer{true, dto, MESSAGE_WINNER});
    loser->SendStatusGame(MessageFromServer{true, dto, MESSAGE_LOSER});
}

void GameMonitor::sendStatusGameWithTie(const GameDTO& dto) {
    for (auto player: this->players) {
        player->SendStatusGame(MessageFromServer{true, dto, MESSAGE_TIE});
    }
}

void GameMonitor::sendStatusGameWithUnfinishedGame(ClientHandler& client, const GameDTO& dto) {
    ClientHandler* otherPlayer =
            (&client == this->players[0]) ? this->players[1] : this->players[0];

    otherPlayer->SendStatusGame(MessageFromServer{true, dto, ""});

    this->isTurn.notify_all();
}

Game GameMonitor::GetGame() const { return this->game; }

bool GameMonitor::isFinished() {
    std::unique_lock<std::mutex> lck(this->mutex);
    GameStatus status = this->game.GetGameStatus();
    return status.haveWinner || status.haveTie;
}
