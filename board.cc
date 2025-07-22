#include "board.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

const int BOARD_SIZE = 8;

Board::Board(): 
        theBoard{BOARD_SIZE, std::vector<Piece>(BOARD_SIZE)}, 
        isWhite{true}, isFinish{false}, prev{""}, 
        whiteP{Player *wp}, balckP{Player *bp} {
    for (int r = 0; r < BOARD_SIZE; ++r) {
        for (int c = 0; c < BOARD_SIZE; ++c) {
            if (c%2 == 0) theBoard[r][c].type = ' ';
            else theBoard[r][c].type = '_';
        }
    }
} // not sure about the player for now

Board::~Board() {
    delete td;
    delete gd;
}

std::vector<int> Board::intPos(std::string pos) {
    std::vector<int> intPos(2);  // Make sure the vector has space for 2 elements

    char col = pos[0];
    char row = pos[1];

    // Convert column character 'a'–'h' to integer 0–7
    intPos[0] = col - 'a';

    // Convert row character '1'–'8' to integer 0–7 using stringstream
    std::stringstream ss;
    ss << row;
    int rowInt;
    ss >> rowInt;

    intPos[1] = rowInt - 1;  // zero-based indexing

    return intPos;
}


void Board::defBoard() { // use add piece to place default pieces
    // black
    //pawn
    for (int c = 0; c < BOARD_SIZE; ++c) {
        theBoard[1][c].type = 'p';
    }
    theBoard[0][0].type = 'r';
    theBoard[0][1].type = 'n';
    theBoard[0][2].type = 'b';
    theBoard[0][3].type = 'q';
    theBoard[0][4].type = 'k';
    theBoard[0][5].type = 'b';
    theBoard[0][6].type = 'n';
    theBoard[0][7].type = 'r';

    //white
    //pawn
    for (int c = 0; c < BOARD_SIZE; ++c) {
        theBoard[6][c].type = 'P';
    }
    theBoard[7][0].type = 'R';
    theBoard[7][1].type = 'N';
    theBoard[7][2].type = 'B';
    theBoard[7][3].type = 'Q';
    theBoard[7][4].type = 'K';
    theBoard[7][5].type = 'B';
    theBoard[7][6].type = 'N';
    theBoard[7][7].type = 'R';
}

void Board::init() {
    delete td; // clean Text display observer
    delete gd; // clean Graphic display observer
    // define text and graphics
    td = new TextDisplay();
    gd = new GraphicDisplay();

    // clear existing board if necessary
    theBoard.clear();
    for (int r = 0; r < n; ++r) {
        theBoard[r].reserve(BOARD_SIZE);
        for (int c = 0; c < n; ++c) {
            theBoard[r].emplace_back(Piece(r,c));
            theBoard[r][c].attach(td); // text
            theBoard[r][c].attach(gd); // graphics
        }
    }

}

char Board::getPiece(std::string pos) {
    std::vector intPos = intPos(pos);
    int r = intPos[1];
    int c= intPos[0];
    return theBoard[r][c].getName();
}

void Board::makeMove(std::string startPos, std::string endPos) {
    std::vector intStartPos = intPos(startPos);
    int startr = intStartPos[1];
    int startc= intStartPos[0];
    std::vector intEndPos = intPos(endPos);
    int endr = intEndPos[1];
    int endc= intEndPos[0];

    Colour c;
    if (isWhite) c = Colour::White;
    else c = Colour::Black;

    pieceType piece = theBoard[startr][startc].getPieceType; //get the pieceType of the moving piece

    if (theBoard[startr][startc].isWhite != isWhite) {
        std::cerr << "Invalid move: must move piece of your colour" << std::endl;
        return;
    }

    if (theBoard[endr][endc] != pieceType::Nothing) {
        // catching the same coloured piece
        if (theBoard[endr][endc].isWhite == isWhite) {
            std::cerr << "Invalid move: Catching the same coloured piece" << std::endl;
            return;
        }
        //if the move catch the other piece
        else theBoard[endr][endc].removePiece();
    }
    theBoard[startr][startc].removePiece()
    theBoard[endr][endc].addPiece(piece, c);
}

void Board::changeTurn() {
    if (isWhite) isWhite = false;
    else isWhite = true;
}

bool Board::isInCheckmate();

bool Board::isInCheck();

bool Board::isInStalemate();

// allow a single undo
void Board::undo() {
    // check if there is previous move
    if (prev == "") std::cerr << "There is no previous action" << std::endl; 
    *this = prev;
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    if(b.td) out << *b.td;
    return out;
}
