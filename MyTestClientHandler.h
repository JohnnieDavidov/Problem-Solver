//
// Created by johnnie on 12/01/2020.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
using namespace std;

class MyTestClientHandler : public ClientHandler {
    CacheManager<string, string>* m_cacheManager{};
    Solver<string, string>* m_solver{};

public:
    MyTestClientHandler(CacheManager<string , string>* cacheManager, Solver<string, string>* solver);
    void handleClient(int inputStream, int outputStream) override ;
};


#endif //EX4_MYTESTCLIENTHANDLER_H
