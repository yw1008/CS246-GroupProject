#include "board.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "info.h"
#include <memory>

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
    if (pos.size() != 2) {
        throw std::invalid_argument("Position must be 2 characters long.");
    }

    char col = pos[0];
    char row = pos[1];

    // Check if column is in 'a' to 'h'
    if (col < 'a' || col > 'h') {
        throw std::invalid_argument("Column must be between 'a' and 'h'.");
    }

    // Check if row is in '1' to '8'
    if (row < '1' || row > '8') {
        throw std::invalid_argument("Row must be between '1' and '8'.");
    }

    std::vector<int> intPos(2);

    // Convert column character 'a'–'h' to integer 0–7
    intPos[0] = col - 'a';

    // Convert row character '1'–'8' to integer 0–7
    // You can simplify conversion by subtracting '1'
    intPos[1] = row - '1';

    return intPos;
}

// std::vector<int> intPos(const std::string& pos) {
//     std::vector<int> intPos(2);  // Make sure the vector has space for 2 elements

//     char col = pos[0];
//     char row = pos[1];

//     // Convert column character 'a'–'h' to integer 0–7
//     intPos[0] = col - 'a';

//     // Convert row character '1'–'8' to integer 0–7 using stringstream
//     std::stringstream ss;
//     ss << row;
//     int rowInt;
//     ss >> rowInt;

//     intPos[1] = rowInt - 1;  // zero-based indexing

//     return intPos;
// }

pieceType getPieceType(char piece) {
    switch (std::toupper(piece)) {
        case 'K': return pieceType::King;
        case 'Q': return pieceType::Queen;
        case 'R': return pieceType::Rook;
        case 'B': return pieceType::Bishop;
        case 'N': return pieceType::Knight;
        case 'P': return pieceType::Pawn;
        default:
            throw std::invalid_argument("Invalid piece type.");
    }
}

Colour getPieceColor(char piece) {
    if (piece == 'P' || piece == 'K' || piece == 'Q' || piece == 'N' || piece == 'B' || piece == 'R') {
        return Colour::Black;
    } else if (piece == 'p' || piece == 'k' || piece == 'q' || piece == 'n' || piece == 'b' || piece == 'r') {
        return Colour::White;
    } else {
        throw std::invalid_argument("Invalid piece color.");
    }
}

void Board::setUp() {
    std::string cmd;

    std::cout << "Entered setup mode. Type 'done' when you're finished.\n";

    while (std::cin >> cmd) {
        if (cmd == "+") { // add piece
            char piece;
            std::string pos;
            std::cin >> piece >> pos;

            try {
                std::vector<int> coords = intPos(pos);
                int row = coords[1];
                int col = coords[0];

                pieceType pt = getPieceType(piece);     // may throw
                Colour c = getPieceColor(piece);        // may throw

                theBoard[row][col].addPiece(pt, c);     // assumes no throw
                theBoard[row][col].setMoveType();       // sets en passant, etc.
            } catch (std::invalid_argument &e) {
                std::cerr << "Error: " << e.what() << '\n';
            }

        } else if (cmd == "-") { // remove piece
            std::string pos;
            std::cin >> pos;

            try {
                std::vector<int> coords = intPos(pos);
                int row = coords[1];
                int col = coords[0];
                if (theBoard[row][col].getPieceType() != ' ') {
                    theBoard[row][col].removePiece(); // Assume you have removePiece() method
                }
            } catch (std::invalid_argument &e) {
                std::cerr << "Error: " << e.what() << '\n';
            }

        } else if (cmd == "=") { // change turn (colour)
            std::string color;
            std::cin >> color;
            if (color == "white") {
                isWhite = true; // Assume you have enum Colour { White, Black }
            } else if (color == "black") {
                isWhite = false;
            } else {
                std::cerr << "Invalid colour.\n";
            }

        } else if (cmd == "done") { // done
            // need to check if the board is in the correct condition
            // kings are not in check
            // pawns are not in the first or the last row
            // cannot leave until those conditions are satisfied
            break;
        } else { // input command error
            std::cerr << "Unknown command.\n"; 
        }
    }
    std::cout << "Exited setup mode.\n"; // finish the setup
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
    blackK = {0, 4};
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
    whiteK = {4, 7};
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

// need as a piece type? or not even needed
char Board::getPiece(std::string pos) {
    std::vector<int>  coords = intPos(pos);
    int r = coords [1];
    int c= coords [0];
    return theBoard[r][c].getType();
}

void Board::makeMove(std::string startPos, std::string endPos) {
    // need to check if the move make player him/herself check
    int startr, startc, endr, endc;

    try {
        std::vector<int> intStartPos = intPos(startPos);
        startc = intStartPos[0];
        startr = intStartPos[1];
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid move: start position error - " << e.what() << std::endl;
        return;
    }

    try {
        std::vector<int> intEndPos = intPos(endPos);
        endc = intEndPos[0];
        endr = intEndPos[1];
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid move: end position error - " << e.what() << std::endl;
        return;
    }

    // std::vector<int>  intStartPos = intPos(startPos);
    // int startr = intStartPos[1];
    // int startc= intStartPos[0];
    // std::vector<int>  intEndPos = intPos(endPos);
    // int endr = intEndPos[1];
    // int endc= intEndPos[0];

    // Colour c;
    // if (isWhite) c = Colour::White;
    // else c = Colour::Black;

    // pieceType piece = theBoard[startr][startc].getPieceType(); //get the pieceType of the moving piece

    // // check if the endposition is out of scope
    // if (endr < 0 || endr > 7 || endc < 0 || endc > 7) {
    //     std::cerr << "Invalid move: end position is out of scope" << std::endl;
    //     return;
    // }

    Colour c;
    if (isWhite) c = Colour::White;
    else c = Colour::Black;

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

    Position diffPos;
    diffPos.col = endc - startc;
    diffPos.row = endr - startr;
    vector<moveType> possibleMove = theBoard[startr][startc].getMoveType();
    moveType correctMove;
    if (possibleMove[1].repeatable) {
        for (int i = 0; i < possibleMove.size; ++i) {
            if (possibleMove[i].rowChange < 0 && diffPos.row < 0) {
                if (possibleMove[i].colChange < 0 && diffPos < 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange > 0 && diffPos > 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange == 0 && diffPos == 0) {
                    correctMove = possibleMove[i];
                }
            } else if (possibleMove[i].rowChange > 0 && diffPos.row > 0) {
                if (possibleMove[i].colChange < 0 && diffPos < 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange > 0 && diffPos > 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange == 0 && diffPos == 0) {
                    correctMove = possibleMove[i];
                }
            } else if (possibleMove[i].rowChange == 0 && diffPos.row == 0) {
                if (possibleMove[i].colChange < 0 && diffPos < 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange > 0 && diffPos > 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange == 0 && diffPos == 0) {
                    correctMove = possibleMove[i];                
                }
            }
        }
        
        for (int j = 1; j < BOARD_SIZE + 1; ++j) {
            int tempc = correctMove.colChange * j + startc;
            int tempr = correctMove.rowChange * j + startr;

            if (tempc == endc && tempr == endr) break; // escape if the loop gets to the end posisiton
            
            if (theBoard[tempr][tempc].getPieceType() != pieceType::Nothing) {
                std::cerr << "Invalid move: another piece blocks the way" << std::endl;
                return;
            }
        } 
    }

    if (theBoard[endr][endc].getPieceType() != pieceType::Nothing) {
        // catching the same coloured piece
        if (theBoard[endr][endc].getColour() == c) {
            std::cerr << "Invalid move: Catching the same coloured piece" << std::endl;
            return;
        }
        //if the move catch the other piece
        else {
            prev.removedPiece = theBoard[endr][endc].getPieceType();
            prev.removedColour = theBoard[endr][endc].getColour();
            theBoard[endr][endc].removePiece();
        }
    }
    else {
        prev.removedPiece = theBoard[endr][endc].getPieceType();
        prev.removedColour = theBoard[endr][endc].getColour();
    }
    prev.startPos.col = startc;
    prev.startPos.row = startr;
    prev.endPos.col = endc;
    prev.endPos.row = endr;
    prev.isEmpty = false;
    theBoard[startr][startc].removePiece();
    theBoard[endr][endc].addPiece(piece, c);

    if(theBoard[endr][endc].getPieceType() == pieceType::King){
        if(theBoard[endr][endc].getColour() == Colour::White){
            whiteK = {endc, endr};
        } else {
            blackK = {endc, endr};
        }
    }
}

void Board::changeTurn() {
    if (isWhite) isWhite = false;
    else isWhite = true;
}

std::vector<std::unique_ptr<Position>> Board::getNextMove(std::string startPos){
    std::vector<std::unique_ptr<Position>> nextPos;
    std::vector intStartPos = intPos(startPos);
    int startr = intStartPos[1];
    int startc= intStartPos[0];
    std::vector<moveType> movetypes = theBoard[startr][startc].getMoveType();
    for(int j = 0; j < movetypes.size(); ++j){
        moveType tempMT = movetypes[j];
        for(int i = 1; i < BOARD_SIZE + 1; ++i){
            int tempR = startr + i*tempMT.rowChange;
            int tempC = startc + i*tempMT.colChange;
            if(tempR =< 8 && tempC =< 8 && tempR >= 0 && tempC >= 0){
                Position next{tempC, tempR};
                nextPos.emplace_back(next);
            }
        }
    }
    return nextPos;
} //Use it to a = getNextMove(...); theBoard[a[i].row][a[i].col].notify(..., true, true)

string Board::isInCheck(){
    int wC = whiteK.col;
    int wR = whiteK.row;
    int bC = blackK.col;
    int bR = blackK.row;
    if(theBoard[wR][wC].getState().stateType == stateType::whiteCheck || theBoard[wR][wC].getState().stateType == stateType::bothCheck){
        if(theBoard[bR][bC].getState().stateType == stateType::blackCheck || theBoard[bR][bC].getState().stateType == stateType::bothCheck){
            return "both";
        } else{
            return "white";
        }
    } else if(theBoard[bR][bC].getState().stateType == stateType::blackCheck || theBoard[bR][bC].getState().stateType == stateType::bothCheck){
        if(theBoard[wR][wC].getState().stateType == stateType::whiteCheck || theBoard[wR][wC].getState().stateType == stateType::bothCheck){
            return "both";
        } else{
            return "black";
        }
    } else {
        return "nothing";
    }
}

bool Board::whiteKingCanMove(){
    std::vector<Position> nextW = theBoard[whiteK.row][whiteK.col].nextMove();
    for(int i = 0; i < nextW.size(); ++i){
        Piece nextMove = theBoard[whiteK.row + nextW[i].row][whiteK.col + nextW[i].col];
        if(nextMove.getColour() == Colour::White || nextMove.getState().stateType == stateType::whiteCheck || nextMove.getState().stateType == stateType::bothCheck){
            return false;
        }
    }
    return true;
}

bool Board::blackKingCanMove(){
    std::vector<Position> nextB = theBoard[blackK.row][blackK.col].nextMove();
    for(int i = 0; i < nextB.size(); ++i){
        Piece nextMove = theBoard[blackK.row + nextB[i].row][blackK.col + nextB[i].col];
        if(nextMove.getColour() == Colour::Black || nextMove.getState().stateType == stateType::blackCheck || nextMove.getState().stateType == stateType::bothCheck){
            return false;
        }
    }
    return true;
}

// allow a single undo
void Board::undo() {
    // check if there is previous move
    if (prev.isEmpty) {
        std::cerr << "There is no previous action" << std::endl; 
        return;
    }
    pieceType movedPiece = theBoard[prev.endPos.row][prev.endPos.col].getPieceType();
    Colour movedColor = theBoard[prev.endPos.row][prev.endPos.col].getColour();
    // return moved piece
    theBoard[prev.startPos.row][prev.startPos.col].addPiece(movedPiece, movedColor);
    theBoard[prev.endPos.row][prev.endPos.col].removePiece();
    // return removed piece if there exists
    if (prev.removedPiece != pieceType::Nothing) {
        theBoard[prev.endPos.row][prev.endPos.col].addPiece(prev.removedPiece, prev.removedColour);
    }
    prev.isEmpty = true;
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    if(b.td) out << *b.td;
    return out;
}
