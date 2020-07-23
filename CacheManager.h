//
// Created by johnnie on 15/01/2020.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include "string"
#include <strings.h>

using namespace std;

template <class P, class S>
class CacheManager {
public:
    virtual bool isThereSolution(P prob) = 0;
    virtual void writeSolution(P prob, S sol) = 0;
    virtual S getSolution(P prob) = 0;
    //virtual string toString(P prob) = 0;
};


#endif //EX4_CACHEMANAGER_H
