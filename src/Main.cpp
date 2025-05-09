#include <GameManager.hpp>

int main() {
    GameManager manager;
    for (int i = 0; i < 250; i++) {
        cout << i << ". Game: ";
        manager.computerVScomputer();
        cout << "\n";
    }
    while (true) {
        manager.playerVScomputer();
    }
    return 0;
}