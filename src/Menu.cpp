#include <Menu.hpp>

Menu::Menu() {}

void Menu::goster() const {
    GameManager manager;
    int choice;
    
    while (true) {
        system("cls");
        cout << "\n  === AIAPAWN ===\n\n";
        cout << "Choose game mode\n";
        cout << "1. Player VS Player\n";
        cout << "2. Player VS Computer\n";
        cout << "3. Computer VS Computer\n";
        cout << "4. Close\n";
        cout << "=> ";
        cin >> choice;

        if (choice == 1) {
            manager.playerVSplayer();
        } else if (choice == 2) {
            manager.playerVScomputer();
        } else if (choice == 3) {
            manager.computerVScomputer();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid Choice\n";
        }
    }
}