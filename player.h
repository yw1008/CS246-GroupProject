#ifndef PLAYER_H
#define PLAYER_H

class Board;

class Player {
    bool colour;
    int level; // 0 for the human otherwise, level of the computer
public:
    // Constructor
    Player(bool isWhite, int lv);

    // Returns true if the player is human
    //bool isHuman() const;

    virtual void move(Board &b) = 0;

    // Returns true if the player is white
    bool isWhite() const;

    int getLevel() const;

    // Destructor
    virtual ~Player();
};

#endif
