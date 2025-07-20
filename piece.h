#ifndef PIECE_H
#define PIECE_H
#include "subject.h"
#include "observer.h"
#include "info.h"
#include <vector>

using namespace std;

struct moveType{
    int colChange, rowChange;
    bool repeatable; // true for sliders (B,R,Q), false for “leapers” (N,K,P)
};

class Piece: public Subject, public Observer {
    protected:
        Position pos;
        bool isAlive;
        char type;
        const std::vector<moveType> possibleWays;
    public:
        bool isValid();

        pieceType getType() const;

        void notify() override;
};

#endif
