#include <PvC.hpp>

int PvC::getColourFromPlayer() {
    int choice;
    
    while (true) {
        cout << "\nEnter the colour you want to play\n";
        cout << "1. WHITE\n";
        cout << "2. BLACK\n";
        cout << "3. RANDOM\n";
        cout << "=> ";
        cin >> choice;

        if (choice == 1) {
            return WHITE;
        } else if (choice == 2) {
            return BLACK;
        } else if (choice == 3) {
            return (generateRandomNumber(0, 1) == 0) ? WHITE : BLACK;
        } else {
            cout << "Invalid Choice\n";
        }
    }
}

void PvC::start() {
    int colourOfPlayer = getColourFromPlayer();
    stack<Position*> positionsOfComputer;
    while (isGameOver() == NOT_OVER) {
        Print::print(board);
        if (colourOfPlayer == turn) {
            changeBoard(getMoveFromUser());
        } else {
            changeBoard(getMoveFromComputer(positionsOfComputer));
        }
        turn = (turn == WHITE) ? BLACK : WHITE;
    }
    Print::print(board);
    printTheGameResult(isGameOver());
}

PvC::PvC(PositionList* positionList) 
    : Game(positionList) {
    start();
}