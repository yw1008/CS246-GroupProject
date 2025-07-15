#ifndef PLAYER_H
#define PLAYER_H

class Player {
    bool HumanOrComputer;
    bool colour;

public:
    // Constructor
    Player(bool isHuman, bool isWhite);

    // Returns true if the player is human
    bool isHuman() const;

    // Returns true if the player is white
    bool isWhite() const;

    // Destructor
    virtual ~Player();
};

#endif
