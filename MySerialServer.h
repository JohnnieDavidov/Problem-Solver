//
// Created by johnnie on 12/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

class MySerialServer : public Server {
    int m_fd{};
    int m_socketFd;
    sockaddr_in address;
    bool isConnect = false;

public:
    int open(int port, ClientHandler* c) override ;
    void stop() override ;
    void start(ClientHandler* c);
};


#endif //EX4_MYSERIALSERVER_H
