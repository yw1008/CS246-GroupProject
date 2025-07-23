#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include "board.h"

class Human : public Player {
public:
    // Constructor
    Human(bool isWhite);

    // // Perform a move 
    // void move(Game &game);
    
    // Destructor
    ~Human() override;
};

#endif
