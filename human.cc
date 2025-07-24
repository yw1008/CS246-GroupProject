#include "human.h"
#include <iostream>
#include <string>
#include "game.h"
#include "board.h"

using namespace std;

Human::Human(bool isWhite, int lv) : Player(isWhite, lv) {}

//Human::~Human() = default;

void Human::move(std::string &startPos, std::string &endPos, Board* b) {
    // string startPos, endPos;
    // if (!(cin >> startPos >> endPos)) {
    //     cerr << "Invalid input: must enter to positions" << endl;
    // }
    b->makeMove(startPos, endPos);
    
}
