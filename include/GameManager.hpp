#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


#include <PvP.hpp>
#include <PvC.hpp>
#include <CvC.hpp>


class GameManager {
    public:
    PositionList* positionList;

    
    public:
    GameManager();
    ~GameManager();

    void playerVSplayer();
    void playerVScomputer();
    void computerVScomputer();
};
#endif // GAMEMANAGER_H