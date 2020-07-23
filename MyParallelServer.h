//
// Created by johnnie on 19/01/2020.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include "Server.h"

class MyParallelServer : public Server {
    int m_socketFd;
    sockaddr_in address;
    bool isConnect = false;
public:
    int open(int port,ClientHandler* c) override;
    void stop() override;
};


#endif //EX4_MYPARALLELSERVER_H
