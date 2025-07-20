#ifndef STATE_H
#define STATE_H

enum class stateType {Nothing, Check};

struct State{
    stateType stateType;
    bool hasMoved; //for the Pawn class & King-Rook castling
};

#endif
