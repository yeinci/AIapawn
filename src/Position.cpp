#include <Position.hpp>

Position::Position(int board[3][3], int turn, vector<Move>* moves) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->board[i][j] = board[i][j];
        }
    }
    this->moves = moves;
    this->turn = turn;
    next = nullptr;
    preferedMoveIndex = NONE;
}