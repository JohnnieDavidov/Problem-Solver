//
// Created by zvi on 1/12/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searcheable.h"
#include <string>

using namespace std;

template <class T>
class Searcher {
public:
    virtual vector<State<T>> search(Searcheable<T>* problem) = 0;
    double pathCost(vector<State<T>> path) {
        double cost = 0;
        int vectorSize = path.size();
        for(int i = 0; i < vectorSize; i++) {
            cost += path[i].getCost();
        }
        return cost;
    }
    int NumOfState(vector<State<T>> path) {
        return path.size();
    }

};
#endif //EX4_SEARCHER_H