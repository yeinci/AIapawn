#ifndef PVC_H
#define PVC_H

#include <Game.hpp>

class PvC : public Game {
    private:
    void start() override;
    int getColourFromPlayer();

    public:
    PvC(PositionList*);
};

#endif // PVC_H 