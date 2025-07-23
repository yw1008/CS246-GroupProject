#ifndef STATE_H
#define STATE_H
#include "info.h"

enum class stateType {Nothing, whiteCheck, blackCheck, bothCheck};

struct State{
    stateType sT;
    Colour colour;
};

#endif
