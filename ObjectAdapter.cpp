//
// Created by johnnie on 17/01/2020.
//

#include <vector>
#include "ObjectAdapter.h"
#include <sstream>


string pathToString(vector<State<Vertax>> path) {
    string strPath = "";
    int size = path.size();
    for (int i = 1; i < size; i++) {
        if (i != 1) {
            strPath += " ";
        }
        int i1 = path[i].getState()->getI();
        int j1 = path[i].getState()->getJ();
        int i0 = path[i-1].getState()->getI();
        int j0 = path[i-1].getState()->getJ();
        if (i1 < i0) {
            strPath += "Up";
        } else if (i1 > i0) {
            strPath += "Down";
        } else if (j1 > j0) {
            strPath += "Right";
        } else if (j1 < j0) {
            strPath += "Left";
        }
        int cost = path[i].getCostFromInitial();
        std::stringstream ss;
        ss << cost;
        strPath += " (" + ss.str() + ")";
    }
    return strPath;
}

string ObjectAdapter::solve(vector<string>* prob) {
    Searcheable<Vertax>* matrix = new SearcheableMatrix(*prob);
    vector<State<Vertax>> astarPath = astar->search(matrix);
    return pathToString(astarPath);
}
