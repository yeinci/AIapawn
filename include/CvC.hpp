#ifndef CVC_H
#define CVC_H

#include <Game.hpp>

class CvC : public Game {
    private:
    void learnFromMistake(stack<Position*>&);
    void resetPreferedMoves(stack<Position*>&);
    void start() override;

    public:
    CvC(PositionList*);
};

#endif // CVC_H