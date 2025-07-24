#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"
#include "board.h"
#include <memory>

class Computer : public Player {

public:
    Computer(bool isWhite, int level);
    int getLevel() const;
    void move(std::string startPos, std::string endPos, std::unique_ptr<Board> board) override;
    //~Computer() override;

    void moveLevel1(unique_ptr<Board> board);
    // void moveLevel2(Board &board);
    // void moveLevel3(Board &board);
};

#endif
