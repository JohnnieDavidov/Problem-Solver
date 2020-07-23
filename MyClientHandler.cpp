//
// Created by johnnie on 17/01/2020.
//

#include "MyClientHandler.h"
#include "string.h"
#include "vector"

MyClientHandler::MyClientHandler(CacheManager<string, string> *cacheManager,
                                 Solver<vector<string>*, string> *solver) {
    m_cacheManager = cacheManager;
    m_solver = solver;
}

void MyClientHandler::handleClient(int inputStream, int outputStream) {
    vector<string> my_vector;
    string strCache;
    string line;
    while(strcmp(line.c_str(), "end") != 0) {
        char buffer[1000] = {0};
        read(inputStream, buffer, sizeof(buffer));
        //cout<<buffer<<endl;
        line = buffer;
        cout<<line<<endl;
        strCache += buffer;
        my_vector.push_back(buffer);
    }

    string sol;
    if(m_cacheManager->isThereSolution(strCache)) {
        sol = m_cacheManager->getSolution(strCache);
    }
    else {
        sol =  m_solver->solve(&my_vector);
        m_cacheManager->writeSolution(strCache, sol);
    }
    const char* msg = sol.c_str();
    send(outputStream,msg, sol.size(), 0);
}
