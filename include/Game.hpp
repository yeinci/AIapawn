#ifndef GAME_H
#define GAME_H

#include <RandomNumberGenerator.hpp>
#include <PositionList.hpp>
#include <Print.hpp>
#include <string>
#include <stack>


class Game {
    protected:
    int board[3][3];
    int turn;
    PositionList* positionList;

    string getNotationName(int, int, int);
    vector<Move>* findValidMoves();
    Move getMoveFromUser();
    Move getMoveFromComputer(stack<Position*>&);
    void changeBoard(Move);
    int isGameOver();
    void printTheGameResult(int);

    public:
    void print();
    virtual void start() = 0;
    Game(PositionList*);
};

#endif // GAME_H