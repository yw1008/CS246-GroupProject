#include "human.h"
#include <iostream>
#include <string>
#include "game.h"
#include "board.h"

Human::Human(bool isWhite, int lv) : Player(isWhite, lv) {}

Human::~Human() = default;

void Human::move(Board &b) {
    std::string from, to;
    std::cout << "Enter your move: ";
    std::cin >> from >> to;
    b.makeMove(from, to);
}
