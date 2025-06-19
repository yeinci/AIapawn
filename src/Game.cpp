#include <Game.hpp>

string Game::getNotationName(int row, int col, int direction) {
    string result = "";

    if (col == 0) {
        result += 'A';
    } else if (col == 1) {
        result += 'B';
    } else {
        result += 'C';
    } if (row == 0) {
        result += '1';
    } else if (row == 1) {
        result += '2';
    } else {
        result += '3';
    } if (direction == LEFT) {
        result += " Diagonal Left";
    } else if (direction == FORWARD) {
        result += " Forward";
    } else {
        result += " Diagonal Right";
    }
    return result;
}

vector<Move>* Game::findValidMoves() {
    vector<Move>* result = new vector<Move>();
    if (turn == WHITE) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == WHITE) {
                    if (j - 1 >= 0 && i + 1 <= 2 && board[i + 1][j - 1] == BLACK) {
                        result->push_back(Move(i, j, LEFT));
                    } if (i + 1 <= 2 && board[i + 1][j] == EMPTY) {
                        result->push_back(Move(i, j, FORWARD));
                    } if (j + 1 <= 2 && i + 1 <= 2 && board[i + 1][j + 1] == BLACK) {
                        result->push_back(Move(i, j, RIGHT));
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == BLACK) {
                    if (j + 1 <= 2 && i - 1 >= 0 && board[i - 1][j + 1] == WHITE) {
                        result->push_back(Move(i, j, LEFT));
                    } if (i - 1 >= 0 && board[i - 1][j] == EMPTY) {
                        result->push_back(Move(i, j, FORWARD));
                    } if (j - 1 >= 0 && i - 1 >= 0 && board[i - 1][j - 1] == WHITE) {
                        result->push_back(Move(i, j, RIGHT));
                    }
                }
            }
        }
    }
    return result;
}

Move Game::getMoveFromUser() {
    vector<Move>* validMoves = findValidMoves();
    int size = validMoves->size();
    int choice;
    
    while (true) {
        cout << "\nEnter the move you want to play\n";
        for (int i = 0; i < size; i++) {
            Move move = validMoves->at(i);
            cout << i + 1 << ". " << getNotationName(move.row, move.col, move.direction) << "\n";
        }
        cout << "=> ";
        cin >> choice;
        choice--;
        if (choice < 0 || choice >= size) {
            cout << "Invalid choice\n";
        } else {
            return validMoves->at(choice);
        }
    }
    delete validMoves;
}

Move Game::getMoveFromComputer(stack<Position*>& positions) {
    vector<Move>* validMoves = findValidMoves();
    Move backup = validMoves->at(0);

    Position* position = positionList->search(board, turn, validMoves);
    int size = position->moves->size();
    
    positions.push(position);

    if (size == 0) {
        return backup;
    }

    int chosenMove;
    if (position->preferedMoveIndex != NONE) {
        chosenMove = position->preferedMoveIndex;
    } else {
        chosenMove = generateRandomNumber(0, size - 1);
        position->preferedMoveIndex = chosenMove;
    }

    return position->moves->at(chosenMove);
}


void Game::changeBoard(Move move) {
    board[move.row][move.col] = EMPTY;
    if (turn == WHITE) {
        if (move.direction == LEFT) {
            board[move.row + 1][move.col - 1] = WHITE;
        } else if (move.direction == FORWARD) {
            board[move.row + 1][move.col] = WHITE;
        } else {
            board[move.row + 1][move.col + 1] = WHITE;
        }
    } else {
        if (move.direction == LEFT) {
            board[move.row - 1][move.col + 1] = BLACK;
        } else if (move.direction == FORWARD) {
            board[move.row - 1][move.col] = BLACK;
        } else {
            board[move.row - 1][move.col - 1] = BLACK;
        }
    }
}

void Game::printTheGameResult(int winner) {
    if (winner == WHITE_WON) {
        cout << "THE WINNER IS WHITE";
    } else if (winner == BLACK_WON) {
        cout << "THE WINNER IS BLACK";
    } else {
        cout << "GAME IS DRAW";
    }
    cin.ignore();
    cin.get();
}

int Game::isGameOver() {
    for (int j = 0; j < 3; j++) {
        if (board[2][j] == WHITE) {
            return WHITE_WON;
        } if (board[0][j] == BLACK) {
            return BLACK_WON;
        }
    }
    if (findValidMoves()->size() == 0) {
        return DRAW;
    }
    return NOT_OVER;
}

Game::Game(PositionList* positionList) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0) {
                board[i][j] = WHITE;
            } else if (i == 1) {
                board[i][j] = EMPTY;
            } else {
                board[i][j] = BLACK;
            }
        }
    }
    turn = WHITE;
    this->positionList = positionList;
}

void Game::print() {
    positionList->print();
}