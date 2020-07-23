//
// Created by zvi on 1/20/20.
//

#ifndef EX4_SEARCHEABLEMATRIX_H
#define EX4_SEARCHEABLEMATRIX_H


#include "Searcheable.h"
#include "State.h"
#include "Vertax.h"
#include <string>
#include "math.h"

class SearcheableMatrix: public Searcheable<Vertax> {
private:
    int rowNum;
    int colNum;
    vector<vector<State<Vertax>>> Matrix;
public:
    SearcheableMatrix(vector<string> input);
    State<Vertax> getInitialState() override ;
    State<Vertax> getGoalState() override ;
    bool isGoalState(State<Vertax> state) override ;
    bool isInitialState(State<Vertax> state) override ;
    void setGoalStateFather(State<Vertax>* father) override ;
    void setGoalStateCost(double cost) override ;
    double heuristicDistance(State<Vertax> current, State<Vertax> goal) override ;
    vector<State<Vertax>> getAllPossibleStates(State<Vertax> state) override ;
    State<Vertax> stringToState(string row);

};

#endif //EX4_SEARCHEABLEMATRIX_H
