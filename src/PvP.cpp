#include <PvP.hpp>

void PvP::start() {
    while (isGameOver() == NOT_OVER) {
        Print::print(board);
        changeBoard(getMoveFromUser());
        if (turn == WHITE) {
            turn = BLACK;
        } else {
            turn = WHITE;
        }
    }
    Print::print(board);
    printTheGameResult(isGameOver());
}

PvP::PvP(PositionList* positionList)
    : Game(positionList) {
    start();
}