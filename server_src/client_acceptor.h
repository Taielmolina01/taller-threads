#ifndef CLIENT_ACCEPTOR_H
#define CLIENT_ACCEPTOR_H

#include <string>
#include <vector>

#include "../common_src/communication_ended.h"
#include "../common_src/liberror.h"
#include "../common_src/socket.h"
#include "../common_src/thread.h"

#include "client_handler.h"
#include "server_monitor.h"

class ClientAcceptor: public Thread {
private:
    Socket acceptor;
    std::vector<ClientHandler*> clients;
    ServerMonitor serverMonitor;

public:
    explicit ClientAcceptor(const std::string& port);
    void run() override;
    void reap();
    void clear();
};

#endif
