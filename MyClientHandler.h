//
// Created by johnnie on 17/01/2020.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "vector"
using namespace std;

class MyClientHandler :public ClientHandler{
    CacheManager<string, string>* m_cacheManager{};
    Solver<vector<string>*, string>* m_solver{};
public:
    MyClientHandler(CacheManager<string , string>* cacheManager, Solver<vector<string>*, string>* solver);
    void handleClient(int inputStream, int outputStream) override ;
};


#endif //EX4_MYCLIENTHANDLER_H
