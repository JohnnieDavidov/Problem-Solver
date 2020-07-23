#include <iostream>
#include "Server.h"
#include "Solver.h"
#include "ClientHandler.h"
#include "CacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "list"
#include "MyClientHandler.h"
#include "ObjectAdapter.h"
#include "MyParallelServer.h"
#include <vector>
#include <fstream>
#include "string.h"

int countClient = 0;

int main() {
//      Solver<string, string>* solver = new StringReverser();
//    CacheManager<string , string>* mycache = new FileCacheManager<string, string>();
//    ClientHandler* clientHandler = new MyTestClientHandler(mycache, solver);

    Server* myServer = new MyParallelServer();
    Solver<vector<string>*, string>* solver = new ObjectAdapter();
    CacheManager<string , string>* my_cache = new FileCacheManager<string, string>();
    ClientHandler* clientHandler = new MyClientHandler(my_cache, solver);

    myServer->open(5600, clientHandler);
    myServer->stop();


    return 0;
}