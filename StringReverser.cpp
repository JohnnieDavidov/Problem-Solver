//
// Created by johnnie on 16/01/2020.
//

#include "StringReverser.h"


string StringReverser::solve(string prob) {
    int n = prob.length();
    string sol;
    // Swap character starting from two
    // corners
    for (int i = 0; i < n/2; i++)
        swap(prob[i], prob[n - i - 1]);
    return prob;
}
