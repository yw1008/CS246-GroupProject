#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Board.h"

class Computer : public Player {
    int level;  // Difficulty level

public:
    // Constructor
    Computer(bool isWhite, int level);

    // Get the difficulty level
    int getLevel() const;

    // Perform a move
    void move(Board &board);

    // Destructor
    ~Computer() override;
};

#endif
