#include "textdisplay.h"
#include <iostream>

TextDisplay::TextDisplay() {
    for (std::size_t r = 0; r < boardSize; ++r) {
        for (std::size_t c = 0; c < boardSize; ++c) {
            if (r%2 == c%2) theBoard[r][c].type = '_'; //black cell
            else theBoard[r][c].type = ' '; //white cell
        }
    }
}

void notify(Subject &whoNotified) override {
    // need end position and the type of the piece (with color) that is moved. 
    // for now just assume each variable represent those two
    std::vecotr<std::size_t> endPos;
    char piece;
    std::size_t r = endPos[0], c = endPos[1];
    theTD[r][c] = piece;
    // also need to update caught piece?
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    std::size_t colNum = boardSize;
    for (std::size_t r = 0; r < boardSize; ++r) {
        out << colNum << " ";
        --colNum;
        for (std::size_t c = 0; c < boardSize; ++c) {
            out << td[r][c];
        }
        out << std::endl;
    }
    out << std::endl;
    out << " abcdefgh" << std::endl;
    return out;
}
