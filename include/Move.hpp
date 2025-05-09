#ifndef MOVE_H
#define MOVE_H

#include <Naming.hpp>

struct Move {
    int row;
    int col;
    int direction;

    Move(int, int, int);
};

#endif // MOVE_H