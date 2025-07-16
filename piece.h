#ifndef PIECE_H
#define PIECE_H
#include "subject.h"
#include "observer.h"
#include <vector>

using namespace std;

enum class pieceType {Pawn, King, Queen, Rook, Knight, Bishop, White, Black};

class Piece: public Subject, public Observer {
    protected:
        vector<int> pos;
        bool isAlive;
        char type;
    public:
        bool isValid();

        pieceType getType() const;

        void notify() override;
};

#endif
