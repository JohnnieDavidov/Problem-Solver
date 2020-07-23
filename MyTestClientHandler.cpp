//
// Created by johnnie on 12/01/2020.
//

#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "string.h"
extern int countClient;
using namespace std;

MyTestClientHandler::MyTestClientHandler(CacheManager<string, string>* cacheManager, Solver<string, string>* solver) {
    m_cacheManager = cacheManager;
    m_solver = solver;
}


void MyTestClientHandler::handleClient(int inputStream, int outputStream) {
    char buffer[1000];
    while(read(inputStream, buffer, sizeof(buffer)) > 0) {
        string line = buffer;
        string prob = line.substr(0, line.find("\n"));
        prob = prob.substr(0, prob.size() - 1);
        if(strcmp(prob.c_str(), "end") == 0) {
            close(inputStream);
            countClient--;

        }
        string sol = "";
        if(m_cacheManager->isThereSolution(prob)) {
            sol = m_cacheManager->getSolution(prob);
        }
        else {
           sol =  m_solver->solve(prob);
           m_cacheManager->writeSolution(prob, sol);
        }
        sol = sol +"\r\n";
        const char* msg = sol.c_str();
        send(outputStream,msg, sol.size(), 0);
    }
}
