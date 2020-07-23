//
// Created by zvi on 1/20/20.
//

#include "SearcheableMatrix.h"
#include <stdlib.h>

State<Vertax> SearcheableMatrix :: stringToState(string row) {
    string first = "";
    string second = "";
    int comma = 0;
    int length = row.length();
    for(int k = 0; k < length; k++) {
        if (row[k] == ',') {
            comma = 1;
        } else if (!comma) {
            first += row[k];
        } else {
            second += row[k];
        }
    }
    char* tmp = &first[0];
    int i = atoi(tmp);
    char* tmp2 = &second[0];
    int j = atoi(tmp2);
    return this->Matrix[i][j];
}

vector<State<Vertax>> capacityToline(string row, int numRow) {
    vector<State<Vertax>> stateRow;
    int count = 0;
    string num = "";
    int size = row.length();
    for(int i = 0; i < size; i++) {
        if (row[i] == ',') {
            char* n = &num[0];
            int cost = atoi(n);
            Vertax* v = new Vertax(numRow, count);
            count++;
            State<Vertax> s = State<Vertax>(v, cost);
            stateRow.push_back(s);
            num = "";
        } else if (row[i] != ' ') {
            num += row[i];
        }
    }
    char* n = &num[0];
    int cost = atoi(n);
    Vertax* v = new Vertax(numRow, count);
    count++;
    State<Vertax> s = State<Vertax>(v, cost);
    stateRow.push_back(s);
    return stateRow;
}

SearcheableMatrix :: SearcheableMatrix(vector<string> input) {
    int size = input.size();
    //initial col number
    string row = input[0];
    int counter = 1;
    for(int i = 0; i < row.length(); i++) {
        if (row[i] == ',') {
            counter++;
        }
    }
    this->colNum = counter;
    //initial row number
    this->rowNum = size - 3;
    //initial state matrix
    for(int i = 0; i < this->rowNum; i++) {
        string row = input[i];
        this->Matrix.push_back(capacityToline(row, i));
    }
    //initial initial state
    string init = input[size - 3];
    this->initialState = stringToState(init);
    //initial goal state
    string goal = input[size - 2];
    this->goalState = stringToState(goal);
}

State<Vertax> SearcheableMatrix :: getInitialState() {
    return this->initialState;
}

State<Vertax> SearcheableMatrix :: getGoalState() {
    return this->goalState;
}

bool SearcheableMatrix :: isGoalState(State<Vertax> state) {
    Vertax* v = state.getState();
    Vertax* goal = this->goalState.getState();
    if (v->getI() == goal->getI() && v->getJ() == goal->getJ()) {
        return true;
    }
    return false;
}

bool SearcheableMatrix :: isInitialState(State<Vertax> state) {
    Vertax* v = state.getState();
    Vertax* initial = this->initialState.getState();
    if (v->getI() == initial->getI() && v->getJ() == initial->getJ()) {
        return true;
    }
    return false;
}

vector<State<Vertax>> SearcheableMatrix :: getAllPossibleStates(State<Vertax> state) {
    vector<State<Vertax>> neighbors;
    Vertax* ver = state.getState();
    int i = ver->getI();
    int j = ver->getJ();
    if (i > 0 && this->Matrix[i-1][j].getCost() != -1) {
        neighbors.push_back(this->Matrix[i-1][j]);
    }
    if (j > 0 && this->Matrix[i][j-1].getCost() != -1) {
        neighbors.push_back(this->Matrix[i][j-1]);
    }
    if (i < this->rowNum - 1 && this->Matrix[i+1][j].getCost() != -1) {
        neighbors.push_back(this->Matrix[i+1][j]);
    }
    if (j < this->colNum - 1 && this->Matrix[i][j+1].getCost() != -1) {
        neighbors.push_back(this->Matrix[i][j+1]);
    }
    return neighbors;
}

void SearcheableMatrix::setGoalStateFather(State<Vertax> *father) {
    this->goalState.setFather(father);
}

void SearcheableMatrix::setGoalStateCost(double cost) {
    this->goalState.setCostFromInitial(cost);
}

double SearcheableMatrix::heuristicDistance(State<Vertax> current, State<Vertax> goal)  {
    int xDistance = abs(current.getState()->getI() - goal.getState()->getI());
    int yDistance = abs(current.getState()->getJ() - goal.getState()->getJ());
    double distance = sqrt(pow(xDistance,2) + pow(yDistance,2));
    return distance;
}
