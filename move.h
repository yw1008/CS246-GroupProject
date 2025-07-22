#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
    std::string from;
    std::string to;

public:
    // Constructor
    Move(const std::string &from, const std::string &to);

    std::string getFrom() const;
    std::string getTo() const;
};

#endif
