//
// Created by zvi on 1/14/20.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
#include <stack>

template <class T>
class DFS:public Searcher<T> {
private:
    stack<State<T>> black;
    stack<State<T>> gray;
public:

    //reverse the vector
    vector<State<T>> reverseVector(vector<State<T>> path) {
        vector<State<T>> reverse;
        for (int i = path.size() - 1; i >= 0; i--) {
            reverse.push_back(path[i]);
        }
        return  reverse;
    }

    // create path vector
    vector<State<T>> backTrace (Searcheable<T>* problem) {
        vector<State<T>> statePath;
        State<T> goal = problem->getGoalState();
        statePath.push_back(goal);
        while(!problem->isInitialState(goal)) {
            goal = *(goal.getFather());
            statePath.push_back(goal);
        }
        return reverseVector(statePath);
    }

    // check if state in stack (gray/black)
    bool isIn(State<T> state, stack<State<T>> d) {
        if (d.empty()) {
            return false;
        } else {
            stack<State<T>> tmp;
            while (!d.empty()) {
                State<T> front = d.top();
                d.pop();
                if (front.isEqual(state)) {
                    while (!d.empty()) {
                        tmp.push(d.top());
                        d.pop();
                    }
                    while (!tmp.empty()) {
                        d.push(tmp.top());
                        tmp.pop();
                    }
                    return true;
                }
                tmp.push(front);
            }
            while (!tmp.empty()) {
                d.push(tmp.top());
                tmp.pop();
            }
            return false;
        }
    }

    vector<State<T>> search(Searcheable<T>* problem) {
        //start with initial state
        State<T> initial = problem->getInitialState();
        // set distance
        initial.setDistance(0);
        initial.setCostFromInitial(initial.getCost());
        // insert to queue
        initial.setColor('g');
        gray.push(initial);
        //while queue not empty
        while (!gray.empty()) {
            // get first in queue
            State<T> u = gray.top();
            gray.pop();
            //insert to black queue
            u.setColor('b');
            black.push(u);
            //chcek if goal state
            if (problem->isGoalState(u)) {
                problem->setGoalStateFather(u.getFather());
                problem->setGoalStateCost(u.getCostFromInitial());
            }
            // update neighboor
            vector<State<T>> neighboor = problem->getAllPossibleStates(u);
            int size = neighboor.size();
            for (int i = 0; i < size; i++) {
                State<T> s = neighboor[i];
                // if s is white (not in gray and black)
                if (!isIn(s, gray) && !isIn(s, black)) {
                    s.setColor('g');
                    s.setDistance(u.getDistance() + 1);
                    s.setFather(&black.top());
                    s.setCostFromInitial(u.getCostFromInitial() + s.getCost());
                    gray.push(s);
                }
            }
        }
        return backTrace(problem);
    }
};

//    //reverse the vector
//    vector<State<T>> reverseVector(vector<State<T>> path) {
//        vector<State<T>> reverse;
//        for (int i = path.size() - 1; i >= 0; i--) {
//            reverse.push_back(path[i]);
//        }
//        return  reverse;
//    }
//
//    // create path vector
//    vector<State<T>> backTrace (Searcheable<T>* problem) {
//        vector<State<T>> statePath;
//        State<T> goal = problem->getGoalState();
//        statePath.push_back(goal);
//        while(!problem->isInitialState(goal)) {
//            goal = *(goal.getFather());
//            statePath.push_back(goal);
//        }
//        return reverseVector(statePath);
//    }
//
//    // check if state in queue (open/close)
//    bool isIn(State<T> state, queue<State<T>> d) {
//        if (d.empty()) {
//            return false;
//        } else {
//            queue<State<T>> tmp;
//            while (!d.empty()) {
//                State<T> front = d.front();
//                d.pop();
//                if (front.isEqual(state)) {
//                    while (!d.empty()) {
//                        tmp.push(d.front());
//                        d.pop();
//                    }
//                    while (!tmp.empty()) {
//                        d.push(tmp.front());
//                        tmp.pop();
//                    }
//                    return true;
//                }
//                tmp.push(front);
//            }
//            while (!tmp.empty()) {
//                d.push(tmp.front());
//                tmp.pop();
//            }
//            return false;
//        }
//    }
//
//    // recusive iteration to visit
//    void dfs_visited(State<T> s, Searcheable<T>* problem) {
//        //change color to gray
//        s.setColor('g');
//        gray.push(s);
//        // set distance
//        if (s.getFather() != NULL) {
//            s.setDistance(s.getFather()->getDistance() + 1);
//        }
//        // find neighboor
//        vector<State<T>> neighboor = problem->getAllPossibleStates(s);
//        // if not visit recirsive iteration
//        int size = neighboor.size();
//        for (int i = 0; i < size; i++) {
//            State<T> u = neighboor[i];
//            //if goal state
//            if (problem->isGoalState(u)) {
//                problem->setGoalStateFather(&gray.back());
//                problem->setGoalStateCost(u.getCost() + s.getCostFromInitial());
//            }
//            // if u is w (not visited) not in gray and black queue
//            if (!isIn(u, gray) && !isIn(u, black)) {
//                dfs_visited(u, problem);
//                u.setFather(&gray.back());/////////////////////////////////////////
//                u.setCostFromInitial(u.getCost() + s.getCostFromInitial());
//                // change u to black
//                s.setColor('b');
//                black.push(s);
//            }
//        }
////        // change u to black
////        s.setColor('b');
////        black.push(s);
//    }
//
//    vector<State<T>> search(Searcheable<T>* problem) {
//        // start with initial state
//        State<T> initial = problem->getInitialState();
//        //set distance unutual to 0
//        initial.setDistance(0);
//        initial.setCostFromInitial(initial.getCost());
//        dfs_visited(initial, problem);
//        return backTrace(problem);
//    }
//};

#endif //EX4_DFS_H
