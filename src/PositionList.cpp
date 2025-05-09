#include <PositionList.hpp>

PositionList::PositionList() {
    head = nullptr;
}

PositionList::~PositionList() {
    Position* curr = head;
    while (curr != nullptr) {
        Position* next = curr->next;
        delete curr;
        curr = next;
    }
}

void PositionList::append(int board[3][3], int turn, vector<Move>* moves) {
    Position* newPosition = new Position(board, turn, moves);

    if (head == nullptr) {
        head = newPosition;
        return;
    }
    Position* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newPosition;
}

Position* PositionList::search(int board[3][3], int turn, vector<Move>* moves) {
    Position* curr = head;
    Position* prev = nullptr;

    while (curr != nullptr) {
        bool isSame = true;

        if (turn != curr->turn) {
            prev = curr;
            curr = curr->next;
            continue;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != curr->board[i][j]) {
                    isSame = false;
                    break;
                }
            }
            if (!isSame) break;
        }
        if (isSame == true) {
            delete moves;
            return curr;
        }

        prev = curr;
        curr = curr->next;
    }
    append(board, turn, moves);

    return (prev != nullptr) ? prev->next : head;
}

void PositionList::print() {
    Position* curr = head;
    int sayac = 0;
    while (curr != nullptr) {
        cout << "\n" << sayac << ". Position: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << curr->board[i][j];
            }
            cout << "\n";
        }
        cout << "tur: " << curr->turn << "\n";
        cout << "preferedIndex: " << curr->preferedMoveIndex << "\n";
        for (int i = 0; i < curr->moves->size(); i++) {
            Move move = curr->moves->at(i);
            cout << "row: " << move.row << "\n"; 
            cout << "col: " << move.col << "\n"; 
            cout << "direction: " << move.direction << "\n"; 
        }
        sayac++;
        curr = curr->next;
    }
}