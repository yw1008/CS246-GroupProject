#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include "board.h"

class Human : public Player {

public:
    // Constructor
    Human(bool isWhite, int lv);

    // // Perform a move 
    // void move(Game &game);
    void move(Board &board) override;
    
    // Destructor
    ~Human() override;
};

#endif
