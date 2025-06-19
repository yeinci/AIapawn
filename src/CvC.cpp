#include <CvC.hpp>

void CvC::start() {
    int gameState;
    stack<Position*> positionsOfBlack;
    stack<Position*> positionsOfWhite;
    
    do  {
        changeBoard(getMoveFromComputer(turn == WHITE ? positionsOfWhite : positionsOfBlack));
        turn = (turn == WHITE) ? BLACK : WHITE;
        gameState = isGameOver();
    } while (gameState == NOT_OVER);

    printTheGameResult(gameState);

    if (gameState == WHITE_WON) {
        learnFromMistake(positionsOfBlack);
    } else if (gameState == BLACK_WON) {
        learnFromMistake(positionsOfWhite);
    } else { // Draw
        resetPreferedMoves(positionsOfBlack);
        resetPreferedMoves(positionsOfWhite);
    }

}

void CvC::learnFromMistake(stack<Position*>& positions) {
    bool control;

    do {
        control = false;
        vector<Move>* moves = positions.top()->moves;
        int preferedMoveIndex = positions.top()->preferedMoveIndex;

        int size = moves->size();
        if (size != 0) {
            moves->erase(moves->begin() + preferedMoveIndex);
        }
        if (moves->empty()) {
            control = true;
        }
        positions.top()->preferedMoveIndex = NONE;
        positions.pop();

    } while (control);
    resetPreferedMoves(positions);
}

void CvC::resetPreferedMoves(stack<Position*>& positions) {
    int size = positions.size();
    for (int i = 0; i < size; i++) {
        positions.top()->preferedMoveIndex = NONE;
        positions.pop();
    }
}

CvC::CvC(PositionList* positionList) 
    : Game(positionList) {
    start();
}