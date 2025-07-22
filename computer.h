#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include "Board.h"

class Computer : public Player {
    int level;

public:
    Computer(bool isWhite, int level);
    int getLevel() const;
    void move(Board &board);
    ~Computer() override;

private:
    void moveLevel1(Board &board);
    void moveLevel2(Board &board);
    void moveLevel3(Board &board);
};

#endif
