#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <Naming.hpp>
#include <vector>
#include <Move.hpp>
using namespace std;

class Position {
    public:
    int board[3][3];
    int turn;
    Position* next;

    int preferedMoveIndex;
    vector<Move>* moves;

    public:
    Position(int board[3][3], int turn, vector<Move>* moves);
};

#endif // POSITION_H