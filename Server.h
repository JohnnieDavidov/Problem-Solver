//
// Created by johnnie on 12/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <array>
#include <unordered_map>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;
class Server {
public:
    virtual int open(int port, ClientHandler* c) = 0;
    virtual void stop() = 0;
};


#endif //EX4_SERVER_H
