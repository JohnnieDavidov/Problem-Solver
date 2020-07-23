//
// Created by zvi on 1/12/20.
//

#ifndef EX4_SEARCHEABLE_H
#define EX4_SEARCHEABLE_H

#include <vector>
#include "State.h"

using namespace std;

template <class T>
class Searcheable {
protected:
    State<T> initialState;
    State<T> goalState;
public:
    //Searcheable() {}
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual bool isGoalState(State<T> state) = 0;
    virtual bool isInitialState(State<T> state) = 0;
    virtual vector<State<T>> getAllPossibleStates(State<T> state) = 0;
    virtual void setGoalStateFather(State<T>* father) = 0;
    virtual void setGoalStateCost(double cost) = 0;
    virtual double heuristicDistance(State<T> current, State<T> goal) = 0;
};
#endif //EX4_SEARCHEABLE_H