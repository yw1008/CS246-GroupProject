#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include "board.h"
#include <memory>

class Computer : public Player {

public:
    Computer(bool isWhite, int level);
    int getLevel() const;
    void move(std::string &startPos, std::string &endPos, Board *board) override;

    bool isValid(string &startPos, string &endPos, Board *board);

    void moveLevel1(Board *board);
    // void moveLevel2(Board &board);
    // void moveLevel3(Board &board);
};

#endif
