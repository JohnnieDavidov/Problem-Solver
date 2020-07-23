//
// Created by zvi on 1/14/20.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H

#include "Searcher.h"

template <class T>
class AStar:public Searcher<T> {
private:
    queue<State<T>> open;
    queue<State<T>> close;
public:
    //reverse the vector
    vector<State<T>> reverseVector(vector<State<T>> path) {
        vector<State<T>> reverse;
        for (int i = path.size() - 1; i >= 0; i--) {
            reverse.push_back(path[i]);
        }
        return  reverse;
    }

    // return path of states from initial to goal
    vector<State<T>> backTrace(State<T> goal, Searcheable<T>* problem) {
        vector<State<T>> statePath;
//        for (int i = 0; i < close.size(); i++) {
//            State<T> s = close.front();
//            close.pop();
//            cout << s.getHeuristic() << endl;
//        }
        statePath.push_back(goal);
        while(!problem->isInitialState(goal)) {
            goal = *(goal.getFather());
            statePath.push_back(goal);
        }
        return reverseVector(statePath);
    }

    // check if state in queue (open/close)
    bool isIn(State<T> state, queue<State<T>> d) {
        if (d.empty()) {
            return false;
        } else {
            queue<State<T>> tmp;
            while (!d.empty()) {
                State<T> front = d.front();
                d.pop();
                if (front.isEqual(state)) {
                    while (!d.empty()) {
                        tmp.push(d.front());
                        d.pop();
                    }
                    while (!tmp.empty()) {
                        d.push(tmp.front());
                        tmp.pop();
                    }
                    return true;
                }
                tmp.push(front);
            }
            while (!tmp.empty()) {
                d.push(tmp.front());
                tmp.pop();
            }
            return false;
        }
    }

    void setCostInQueue(State<T> s) {
        queue<State<T>> tmp;
        State<T> front = open.front();
        open.pop();
        while(!front.isEqual(s)) {
            tmp.push(front);
            front = open.front();
            open.pop();
        }
        //update minimum f(n)
        if (front.getCostFromInitial() + front.getHeuristic() > s.getCostFromInitial() + s.getHeuristic()) {
            front.setCostFromInitial(s.getCostFromInitial());
            front.setHeuristic(s.getHeuristic());
        }
        tmp.push(front);
        while (!open.empty()) {
            tmp.push(open.front());
            open.pop();
        }
        //return all values to open
        while (!tmp.empty()) {
            open.push(tmp.front());
            tmp.pop();
        }
    }

    // add new state in priority queue
    queue<State<T>> add(queue<State<T>> priority, State<T> s) {
        queue<State<T>> tmp;
        if (priority.empty()) {
            tmp.push(s);
        } else {
            State<T> front = priority.front();
            priority.pop();
            while (!priority.empty() &&
                    front.getCostFromInitial() + front.getHeuristic() < s.getCostFromInitial() + s.getHeuristic()) {
                tmp.push(front);
                front = priority.front();
                priority.pop();
            }
            if (!priority.empty()) {
                tmp.push(s);
                tmp.push(front);
                while (!priority.empty()) {
                    tmp.push(priority.front());
                    priority.pop();
                }
            } else {
                if (front.getCostFromInitial() + front.getHeuristic() < s.getCostFromInitial() + s.getHeuristic()) {
                    tmp.push(front);
                    tmp.push(s);
                } else {
                    tmp.push(s);
                    tmp.push(front);
                }
            }
        }
        return tmp;
    }

    //find cost of state, if not exist return -1
    double findCost(State<T> s, queue<State<T>> in) {
        queue<State<T>> tmp;
        State<T> front;
        double cost;
        while(!in.empty()) {
            front = in.front();
            in.pop();
            if (front.isEqual(s)) {
                return front.getCostFromInitial() + front.getHeuristic();
            }
        }
        return -1;
    }

    //remove State
    queue<State<T>> remove(queue<State<T>> q, State<T> s) {
        queue<State<T>> tmp;
        while (!q.empty()) {
            State<T> front = q.front();
            q.pop();
            if (!front.isEqual(s)) {
                tmp.push(front);
            }
        }
        return tmp;
    }

    int findNeighboor(vector<State<T>> v, vector<double> f) {
        int n = 0;
        double min = f[0];
        for (int i = 1; i < v.size(); i++) {
            if (f[i] < min) {
                min = f[i];
                n = i;
            }
        }
        return n;
    }

    vector<State<T>> search(Searcheable<T>* problem) {
        State<T> goal = problem->getGoalState();
        // insert initial state to open list
        State<T> initial = problem->getInitialState();
        initial.setFather(nullptr);
        initial.setCostFromInitial(initial.getCost());
        initial.setHeuristic(problem->heuristicDistance(initial, goal));
        open = add(open, initial);
        // while open not empty
        while (!open.empty()) {
            // initial State n
            State<T> u = open.front();
            open.pop();
            // add n to close
            close.push(u);
            // check if n is goal
            if (problem->isGoalState(u)) {
                // do back trace
                return backTrace(u, problem);
            }
            // create neighboor list
            vector<State<T>> neighboor = problem->getAllPossibleStates(u);
            // find neighoor with lowesr f(n)
            vector<double> f;
            for (int i = 0; i < neighboor.size(); i++) {
                State<T> s = neighboor[i];
                s.setFather(&close.back());
                s.setCostFromInitial(s.getCost() + u.getCostFromInitial());
                s.setHeuristic(problem->heuristicDistance(s, goal));
                f.push_back(s.getHeuristic() + s.getCostFromInitial());
                neighboor[i] = s;
            }
            int found = 0;
            while (!found) {
                if (neighboor.size()) {
                    int n = findNeighboor(neighboor, f);
                    State<T> s = neighboor[n];
                    // if state not in close and not in open
                    if (!isIn(s, close) && !isIn(s, open)) {
                        // add to open
                        open = add(open, s);
                        found = 1;
                    }
                    neighboor.erase(neighboor.begin()+n);
                    f.erase(f.begin()+n);
                } else {
                    found = 1;
                }
            }
            for(int i = 0; i < neighboor.size(); i++) {
                State<T> s1 = neighboor[i];
                // if state not in close and not in open
                if (!isIn(s1, close) && !isIn(s1, open)) {
                    // add to open
                    open = add(open, s1);
                    // else if this new path is better than previous one
                    // if it is not in OPEN --- add it to OPEN
                } else if (isIn(s1, close) &&
                (findCost(s1, close) > s1.getCostFromInitial()  + s1.getHeuristic())) {
                    open = add(open, s1);
                    close = remove(close, s1);
                    // Otherwise, adjust its priority in OPEN done
                } else if (isIn(s1, open)) {
                    setCostInQueue(s1);
                }
            }
        }
    }
};

#endif //EX4_ASTAR_H
