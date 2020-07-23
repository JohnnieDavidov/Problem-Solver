//
// Created by johnnie on 17/01/2020.
//

#ifndef EX4_OBJECTADAPTER_H
#define EX4_OBJECTADAPTER_H

#include "Solver.h"
#include "Searcher.h"
#include "Vertax.h"
#include "SearcheableMatrix.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"
#include "vector"


class ObjectAdapter : public Solver<vector<string>*, string> {
private:
    Searcher<Vertax>* astar = new AStar<Vertax>();
public:
    string solve(vector<string>* prob) override ;
};


#endif //EX4_OBJECTADAPTER_H
