//
// Created by zvi on 1/12/20.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

template <class T>
class State {
private:
    T* state;
    double cost;
    double costFromInitial = 0;
    State<T>* father = nullptr;
    double distance = -1;
    double heuristic = 0;
    char color = 'w';
    bool visit = false;
public:
    // default constractor
    State() {
        this->state = NULL;
        this->father = NULL;
        this->cost = 0;
    }
    //constractors
    State(T* state, double cost) {
        this->state = state;
        this->cost = cost;
        this->father = nullptr;
    }
    State(T* state, double cost, State<T>* father) {
        this->state = state;
        this->cost = cost;
        this->father = father;
    }
    T* getState() {
        return this->state;
    }
    State<T>* getFather() {
        return this->father;
    }
    double getCost() {
        return this->cost;
    }
    void setCost(double cost) {
        this->cost = cost;
    }
    void setFather(State<T>* father) {
        this->father = father;
    }
    bool visited() {
        this->visit = false;
    }
    bool isVisit() {
        return this->visit;
    }

    bool isEqual(State<T> state) {
        if (state.getState() == this->getState()) {
            return true;
        }
        return false;
    }

    double getCostFromInitial() {
        return this->costFromInitial;
    }

    void setCostFromInitial(double cost) {
        this->costFromInitial = cost;
    }

    char getColor() {
        return this->color;
    }

    void setColor(char c) {
        this->color = c;
    }

    double getDistance() {
        return  this->distance;
    }

    void setDistance(double d) {
        this->distance = d;
    }

    double getHeuristic() {
        return  this->heuristic;
    }

    void setHeuristic(double heuristic) {
        this->heuristic = heuristic;
    }

    bool operator<(State<T> s) {
        if (this->getCost() < s.getCost()) {
            return this;
        } else {
            return s;
        }
    }
};

#endif //EX4_STATE_H