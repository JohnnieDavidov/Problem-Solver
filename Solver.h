//
// Created by johnnie on 15/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include "strings.h"
#include <string>
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
template <class P, class S>
class Solver {
public:
    virtual S solve(P prob) = 0;
};


#endif //EX4_SOLVER_H
