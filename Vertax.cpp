//
// Created by zvi on 1/14/20.
//

#include "Vertax.h"

Vertax :: Vertax(int i, int j) {
    this->i = i;
    this->j = j;
}
int Vertax :: getI() {
    return i;
}

int Vertax :: getJ() {
    return j;
}

bool Vertax :: isEqual(Vertax v) {
    if (v.getJ() == this->getJ() && v.getI() == this->getI()) {
        return true;
    }
    return  false;
}