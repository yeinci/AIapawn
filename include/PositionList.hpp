#ifndef POSITIONLIST_H
#define POSITIONLIST_H

#include <Position.hpp>

class PositionList {
    private:
    Position* head;

    public:
    PositionList();
    ~PositionList();

    void print();
    void append(int board[3][3], int turn, vector<Move>* moves);
    Position* search(int board[3][3], int turn, vector<Move>* moves);
    
};

#endif // POSITIONLIST_H