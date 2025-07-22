#ifndef STATE_H
#define STATE_H

enum class stateType {Nothing, whiteCheck, blackCheck, bothCheck};

struct State{
    stateType stateType;
    Colour colour;
};

#endif
