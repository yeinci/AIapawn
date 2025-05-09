#ifndef PVP_H
#define PVP_H

#include <Game.hpp>

class PvP : public Game {
    private:
    void start() override;

    public:
    PvP(PositionList*);
};

#endif // PVP_H 