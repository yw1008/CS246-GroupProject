#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"
#include "board.h"
#include <memory>

class Human : public Player {

public:
    // Constructor
    Human(bool isWhite, int lv);

    // // Perform a move 
    // void move(Game &game);
    void move(std::string startPos, std::string endPos, unique_ptr<Board> board) override;
    
    // Destructor
    //~Human() override;
};

#endif
