#include "board.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

const int BOARD_SIZE = 8;

// Board::Board(): 
//         theBoard{BOARD_SIZE, std::vector<Piece>(BOARD_SIZE)}, 
//         isWhite{true}, isFinish{false}, prev{""} {
//     for (int r = 0; r < BOARD_SIZE; ++r) {
//         for (int c = 0; c < BOARD_SIZE; ++c) {
//             if (c%2 == 0) theBoard[r][c].type = ' ';
//             else theBoard[r][c].type = '_';
//         }
//     }
// } // not sure about the player for now

Board::~Board() {
    delete td;
    delete gd;
}

std::vector<int> intPos(const std::string& pos) {
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
        theBoard[1][c].addPiece(pieceType::Pawn, Colour::Black);
        theBoard[1][c].setMoveType();
    }
    theBoard[0][0].addPiece(pieceType::Rook, Colour::Black);
    theBoard[0][0].setMoveType();
    theBoard[0][1].addPiece(pieceType::Knight, Colour::Black);
    theBoard[0][1].setMoveType();
    theBoard[0][2].addPiece(pieceType::Bishop, Colour::Black);
    theBoard[0][2].setMoveType();
    theBoard[0][3].addPiece(pieceType::Queen, Colour::Black);
    theBoard[0][3].setMoveType();
    theBoard[0][4].addPiece(pieceType::King, Colour::Black);
    theBoard[0][4].setMoveType();
    theBoard[0][5].addPiece(pieceType::Bishop, Colour::Black);
    theBoard[0][5].setMoveType();
    theBoard[0][6].addPiece(pieceType::Knight, Colour::Black);
    theBoard[0][6].setMoveType();
    theBoard[0][7].addPiece(pieceType::Rook, Colour::Black);
    theBoard[0][7].setMoveType();

    //white
    //pawn
    for (int c = 0; c < BOARD_SIZE; ++c) {
        theBoard[6][c].addPiece(pieceType::Pawn, Colour::White);
        theBoard[6][c].setMoveType();
    }
    theBoard[7][0].addPiece(pieceType::Rook, Colour::White);
    theBoard[7][0].setMoveType();
    theBoard[7][1].addPiece(pieceType::Knight, Colour::White);
    theBoard[7][1].setMoveType();
    theBoard[7][2].addPiece(pieceType::Bishop, Colour::White);
    theBoard[7][2].setMoveType();
    theBoard[7][3].addPiece(pieceType::Queen, Colour::White);
    theBoard[7][3].setMoveType();
    theBoard[7][4].addPiece(pieceType::King, Colour::White);
    theBoard[7][4].setMoveType();
    theBoard[7][5].addPiece(pieceType::Bishop, Colour::White);
    theBoard[7][5].setMoveType();
    theBoard[7][6].addPiece(pieceType::Knight, Colour::White);
    theBoard[7][6].setMoveType();
    theBoard[7][7].addPiece(pieceType::Rook, Colour::White);
    theBoard[7][7].setMoveType();
}

void Board::init() {
    delete td; // clean Text display observer
    delete gd; // clean Graphic display observer
    // define text and graphics
    td = new TextDisplay();
    gd = new GraphicDisplay();

    // clear existing board if necessary
    theBoard.clear();
    for (int r = 0; r < BOARD_SIZE; ++r) {
        theBoard[r].reserve(BOARD_SIZE);
        for (int c = 0; c < BOARD_SIZE; ++c) {
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
    return theBoard[r][c].getPieceType();
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

    pieceType piece = theBoard[startr][startc].getPieceType(); //get the pieceType of the moving piece

    // check if the endposition is out of scope
    if (endr < 0 || endr > 7 || endc < 0 || endc > 7) {
        std::cerr << "Invalid move: end position is out of scope" << std::endl;
        return;
    }

    if (theBoard[startr][startc].getColour() != c) {
        std::cerr << "Invalid move: must move piece of your colour" << std::endl;
        return;
    }

    // check it the movement is correct for the piece type
    Position toPos{endc, endr};
    bool isValid = theBoard[startr][startc].isValid(toPos);
    if(!isValid) {
        std::cerr << "Invalid move for the piece type" << std::endl;
        return;
    }

    vector<moveType> possibleMove = theBoard[startr][startc].getMoveType();
    for (int i = 0; i < possibleMove.size; ++i) {
        // if (possibleMove[i] == toPos) {
        //     std::cerr << "Invalid move for the piece type" << std::endl;
        //     return;
        // }
        

    }

    if (theBoard[endr][endc].getPieceType() != pieceType::Nothing) {
        // catching the same coloured piece
        if (theBoard[endr][endc].getColour() == c) {
            std::cerr << "Invalid move: Catching the same coloured piece" << std::endl;
            return;
        }
        //if the move catch the other piece
        else theBoard[endr][endc].removePiece();
    }
    theBoard[startr][startc].removePiece();
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
