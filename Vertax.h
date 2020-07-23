//
// Created by zvi on 1/14/20.
//

#ifndef EX4_VERTAX_H
#define EX4_VERTAX_H

class Vertax {
private:
    int i;
    int j;
public:
    Vertax() {}
    Vertax(int i, int j);
    int getI();
    int getJ();
    bool isEqual(Vertax v);
};

#endif //EX4_VERTAX_H
