//
// Created by johnnie on 15/01/2020.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H
#include "CacheManager.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename P, typename S>
class FileCacheManager : public CacheManager<P, S>{
private:
    unordered_map<P, S> m_map;
public:
    bool isThereSolution( P prob);
    void writeSolution(S sol, P prob);
    S getSolution(P prob);
    string toString(P prob);
};

template<typename P, typename S>
bool FileCacheManager<P, S>::isThereSolution(P prob) {
    return !(m_map.find(prob) == m_map.end());
}

template<typename P, typename S>
void FileCacheManager<P, S>::writeSolution(S sol, P prob) {
    m_map[prob] = sol;
}

template<typename P, typename S>
S FileCacheManager<P, S>::getSolution(P prob) {
    return m_map[prob];
}

template<typename P, typename S>
string FileCacheManager<P, S>::toString(P prob) {
    std::string s(*prob);
    return s;
}


#endif //EX4_FILECACHEMANAGER_H
