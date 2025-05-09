#include <GameManager.hpp>

GameManager::GameManager() {
    positionList = new PositionList();
}

GameManager::~GameManager() {
    delete positionList;
}

void GameManager::playerVSplayer() {
    PvP game(positionList);
}

void GameManager::playerVScomputer() {
    PvC game(positionList);
}

void GameManager::computerVScomputer() {
    CvC game(positionList);
}