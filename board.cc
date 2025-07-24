#include "board.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "info.h"

using namespace std;

const int BOARD_SIZE = 8;

Board::~Board() {
    delete td;
    // delete gd;
}

vector<int> Board::intPos(string pos) {
    if (pos.size() != 2) {
        throw invalid_argument("Position must be 2 characters long.");
    }

    char col = pos[0];
    char row = pos[1];

    // Check if column is in 'a' to 'h'
    if (col < 'a' || col > 'h') {
        throw invalid_argument("Column must be between 'a' and 'h'.");
    }

    // Check if row is in '1' to '8'
    if (row < '1' || row > '8') {
        throw invalid_argument("Row must be between '1' and '8'.");
    }

    vector<int> ip(2);

    // Convert column character 'a'–'h' to integer 0–7
    ip[0] = col - 'a';

    // Convert row character '1'–'8' to integer 0–7
    // You can simplify conversion by subtracting '1'
    ip[1] = row - '1';
    // the chess board is in reverse order for the row
    ip[1] = 7 - ip[1];

    return ip;
}

pieceType Board::getPieceType(char piece) {
    if (piece == '\0') return pieceType::Nothing; // if piece is empty
    switch (toupper(piece)) {
        case 'K': return pieceType::King;
        case 'Q': return pieceType::Queen;
        case 'R': return pieceType::Rook;
        case 'B': return pieceType::Bishop;
        case 'N': return pieceType::Knight;
        case 'P': return pieceType::Pawn;
        default:
            throw invalid_argument("Invalid piece type.");
    }
}

Colour Board::getPieceColor(char piece) {
    if (piece == 'P' || piece == 'K' || piece == 'Q' || piece == 'N' || piece == 'B' || piece == 'R') {
        return Colour::White;
    } else if (piece == 'p' || piece == 'k' || piece == 'q' || piece == 'n' || piece == 'b' || piece == 'r') {
        return Colour::Black;
    } else if (piece == '\0') { // if piece is empty
        return Colour::Nothing;
    } else {
        throw invalid_argument("Invalid piece color.");
    }
}

void Board::addPieceCount(pieceType pt, Colour c) {
    if (c == Colour::White) {
        if (pt == pieceType::King || pt == pieceType::Queen) {
            if (whitePieceCount[pt] == 1) {
                throw invalid_argument("Cannot add pieceType - over the limit");
                return;
            }
        } else if (pt == pieceType::Bishop || pt == pieceType::Rook || pt == pieceType::Knight) {
            if (whitePieceCount[pt] == 2) {
                throw invalid_argument("Cannot add pieceType - over the limit");
                return;
            }
        } else if (pt == pieceType::Pawn) {
            if (whitePieceCount[pt] == 8) {
                throw invalid_argument("Cannot add pieceType - over the limit");
                return;
            }
        }
        whitePieceCount[pt]++;
    } else {
        if (pt == pieceType::King || pt == pieceType::Queen) {
            if (blackPieceCount[pt] == 1) {
                throw invalid_argument("Cannot add pieceType - over the limit");
                return;
            }
        } else if (pt == pieceType::Bishop || pt == pieceType::Rook || pt == pieceType::Knight) {
            if (blackPieceCount[pt] == 2) {
                throw invalid_argument("Cannot add pieceType - over the limit");
                return;
            }
        } else if (pt == pieceType::Pawn) {
            if (blackPieceCount[pt] == 8) {
                throw invalid_argument("Cannot add pieceType - over the limit");
                return;
            }
        }
        blackPieceCount[pt]++;
    }
}

void Board::removePieceCount(pieceType pt, Colour c) {
    if (c == Colour::White) {
        if (whitePieceCount[pt] == 0) return;
        else whitePieceCount[pt]++;
    } else  {
        if (blackPieceCount[pt] == 0) return;
        else blackPieceCount[pt]++;
    }
}

void Board::setUp(string cmd, string type, string position, string c) {
    // invalid input if board already has that piece
    if (cmd == "+") { // add piece
        char piece = type[0];
        string pos = position;

        try {
            vector<int> coords = intPos(pos);
            int r = coords[1];
            int c = coords[0];
            pieceType pt = getPieceType(piece);     // may throw
            Colour colour = getPieceColor(piece);   // may throw
            addPieceCount(pt, colour);                       // add number of that piece type
            theBoard[r][c].addPiece(pt, colour);    // assumes no throw
            theBoard[r][c].setMoveType();           // sets en passant, etc.
            // track king position
            if (pt == pieceType::King) {
                if (colour == Colour::White) whiteK = {c, r}; 
                else blackK = {c, r};
            }
        } catch (invalid_argument &e) {
            cerr << "Error: " << e.what() << endl;
        }

    } else if (cmd == "-") { // remove piece
        string pos = position;
        char piece = type[0];
        
        try {
            vector<int> coords = intPos(pos);
            int row = coords[1];
            int col = coords[0];
            if (theBoard[row][col].getPieceType() != pieceType::Nothing) {
                theBoard[row][col].removePiece();   // piece is not removed
                pieceType pt = theBoard[row][col].getPieceType();
                Colour colour = theBoard[row][col].getColour();
                removePieceCount(pt, colour);        // remove the number of pieces
            }
            // track king position
            pieceType pt = getPieceType(piece);
            Colour colour = getPieceColor(piece);
            if (pt == pieceType::King) {
                if (colour == Colour::White) whiteK = {-1, -1};
                else blackK = {-1, -1};
            }
        } catch (invalid_argument &e) {
            cerr << "Error: " << e.what() << endl; // print invalid piece type error
        }

    } else if (cmd == "=") { // change turn (colour)
        string color = c;
        if (color == "White") {
            isWhite = true; // Assume you have enum Colour { White, Black }
        } else if (color == "Black") {
            isWhite = false;
        } else {
            cerr << "Invalid colour." << endl;
        }
    } else if (cmd == "done") {
        if (whiteK.col == -1 || whiteK.row == -1 || blackK.col == -1 || blackK.row == -1) {
            throw std::invalid_argument("Invalid: Must have two kings on the board");
        }

        if (isInCheck() == "white" || isInCheck() == "black") { //Not sure to fix error
            throw std::invalid_argument("Invalid: A king is in check during setup");
        }

        int firstRow = 0, lastRow = 7;
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (theBoard[firstRow][j].getPieceType() == pieceType::Pawn ||
                theBoard[lastRow][j].getPieceType() == pieceType::Pawn) {
                throw std::invalid_argument("Invalid: Pawns cannot be in the first or last row");
            }
        }
    }
    cout << "setup successful - board" << endl;
} //setup

std::vector<std::vector<Piece>> Board::getBoard(){
    return theBoard;
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
} //defBoard

void Board::init() {
    delete td; // clean Text display observer
    // delete gd; // clean Graphic display observer
    // define text and graphics
    td = new TextDisplay();
    // gd = new GraphicDisplay();

    // clear existing board if necessary
    theBoard.clear();
    theBoard.resize(BOARD_SIZE);
    for (int r = 0; r < BOARD_SIZE; ++r) {
        theBoard[r].reserve(BOARD_SIZE);
        for (int c = 0; c < BOARD_SIZE; ++c) {
            theBoard[r].emplace_back(Piece(r, c));
            theBoard[r][c].attach(td); // text
            //theBoard[r][c].attach(gd); // graphics
        }
    }
} //init

// need as a piece type? or not even needed
char Board::getPiece(string pos) {
    vector<int>  coords = intPos(pos);
    int r = coords [1];
    int c= coords [0];
    return theBoard[r][c].getType();
}

bool Board::isValidMove(string &startPos, string &endPos) {
    // need to check if the move make player him/herself check
    int startr, startc, endr, endc;

    try {
        vector<int> intStartPos = intPos(startPos);
        startc = intStartPos[0];
        startr = intStartPos[1];
    } catch (const invalid_argument& e) {
        cerr << "Invalid move: start position error - " << e.what() << endl;
        return false;
    }

    try {
        vector<int> intEndPos = intPos(endPos);
        endc = intEndPos[0];
        endr = intEndPos[1];
    } catch (const invalid_argument& e) {
        cerr << "Invalid move: end position error - " << e.what() << endl;
        return false;
    }

    Colour c;
    if (isWhite) c = Colour::White;
    else c = Colour::Black;

    if (theBoard[startr][startc].getColour() != c) {
        cerr << "Invalid move: must move piece of your colour" << endl;
        return false;
    }

    // check it the movement is correct for the piece type
    Position toPos{endc, endr};
    // bool isValid = theBoard[startr][startc].isValid(toPos);
    // if(!isValid) {
    //     cerr << "Invalid move for the piece type" << endl;
    //     return;
    // }

    Position diffPos;
    diffPos.col = endc - startc;
    diffPos.row = endr - startr;
    vector<moveType> possibleMove = theBoard[startr][startc].getMoveType();
    moveType correctMove;
    if (possibleMove[1].repeatable) {
        for (size_t i = 0; i < possibleMove.size(); ++i) {
            if (possibleMove[i].rowChange < 0 && diffPos.row < 0) {
                if (possibleMove[i].colChange < 0 && diffPos.col < 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange > 0 && diffPos.col > 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange == 0 && diffPos.col == 0) {
                    correctMove = possibleMove[i];
                }
            } else if (possibleMove[i].rowChange > 0 && diffPos.row > 0) {
                if (possibleMove[i].colChange < 0 && diffPos.col < 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange > 0 && diffPos.col > 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange == 0 && diffPos.col == 0) {
                    correctMove = possibleMove[i];
                }
            } else if (possibleMove[i].rowChange == 0 && diffPos.row == 0) {
                if (possibleMove[i].colChange < 0 && diffPos.col < 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange > 0 && diffPos.col > 0) {
                    correctMove = possibleMove[i];
                } else if (possibleMove[i].colChange == 0 && diffPos.col == 0) {
                    correctMove = possibleMove[i];                
                }
            }
        }
        
        for (size_t j = 1; j < BOARD_SIZE + 1; ++j) {
            int tempc = correctMove.colChange * j + startc;
            int tempr = correctMove.rowChange * j + startr;

            if (tempc == endc && tempr == endr) break; // escape if the loop gets to the end posisiton
            
            if (theBoard[tempr][tempc].getPieceType() != pieceType::Nothing) {
                cerr << "Invalid move: another piece blocks the way" << endl;
                return false;
            }
        } 
    }

    // Special logic for pawn
    if (theBoard[startr][startc].getPieceType() == pieceType::Pawn) {
        Colour pieceColour = theBoard[startr][startc].getColour();
        int dir = 1;
        if (pieceColour == Colour::White) {
            dir = -1;
        }

        bool isForward = (startc == endc);
        bool isDiagonal = std::abs(startc - endc) == 1 && (endr - startr) == dir;

        // Capture move: must be diagonal and there must be an opponent's piece
        if (isDiagonal) {
            if (theBoard[endr][endc].getPieceType() == pieceType::Nothing ||
                theBoard[endr][endc].getColour() == pieceColour) {
                cerr << "Invalid move: Pawn can only capture diagonally if opponent's piece exists" << endl;
                return false;
            }
            return true;
        }

        // Forward move must be straight
        if (isForward) {
            if (endr - startr == dir &&
                theBoard[endr][endc].getPieceType() == pieceType::Nothing) {
                return true;
            }

            // First double-step
            if ((pieceColour == Colour::White && startr == 6 || pieceColour == Colour::Black && startr == 1) &&
                endr - startr == 2 * dir &&
                theBoard[startr + dir][startc].getPieceType() == pieceType::Nothing &&
                theBoard[endr][endc].getPieceType() == pieceType::Nothing) {
                return true;
            }

            cerr << "Invalid move: Pawn move blocked or invalid distance" << endl;
            return false;
        }
        cerr << "Invalid move: Pawn cannot move this way" << endl;
        return false;
    }


    if (theBoard[endr][endc].getPieceType() != pieceType::Nothing) {
        // catching the same coloured piece
        if (theBoard[endr][endc].getColour() == c) {
            cerr << "Invalid move: Catching the same coloured piece" << endl;
            return false;
        }
    }
    return true;
}


void Board::makeMove(string &startPos, string &endPos) {
    int startr, startc, endr, endc;

    vector<int> intStartPos = intPos(startPos);
    startc = intStartPos[0];
    startr = intStartPos[1];
    vector<int> intEndPos = intPos(endPos);
    endc = intEndPos[0];
    endr = intEndPos[1];

    Colour c;
    if (isWhite) c = Colour::White;
    else c = Colour::Black;
        
    if (theBoard[endr][endc].getPieceType() != pieceType::Nothing) {
        if (theBoard[endr][endc].getColour() != c) {
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
    pieceType piece = theBoard[startr][startc].getPieceType();
    theBoard[startr][startc].removePiece();
    theBoard[endr][endc].addPiece(piece, c);

    if(theBoard[endr][endc].getPieceType() == pieceType::King){
        if(theBoard[endr][endc].getColour() == Colour::White){
            whiteK = {endc, endr};
        } else {
            blackK = {endc, endr};
        }
    }
} //makeMove

void Board::changeTurn() {
    isWhite = !isWhite;
} //changeTurn

vector<Position> Board::allPossibleMoves(){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
            theBoard[i][j].setState(stateType::Nothing, theBoard[i][j].getState().colour);
        }
    }

    vector<Position> nextmoves;

    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
            vector<moveType> next = theBoard[i][j].getMoveType();
            for(size_t k = 0; k < next.size(); ++k){
                if(next[k].repeatable){
                    for(int w = 1; w < BOARD_SIZE + 1; ++w){
                        if(j + w * next[k].colChange < 8 && i + w * next[k].rowChange < 8 && i + w * next[k].rowChange > -1 && j + w * next[k].colChange > -1){
                            Position nextP{j + w * next[k].colChange, i + w * next[k].rowChange};
                            if(theBoard[i][j].getColour() == Colour::White){
                                if(theBoard[i + next[k].rowChange][j + next[k].colChange].getState().sT == stateType::blackCheck){ // blackCheck is the piece where black piece can check
                                    theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::bothCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                                } else{
                                    theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::whiteCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                                }
                            } else if(theBoard[i][j].getColour() == Colour::Black){
                                if(theBoard[i + next[k].rowChange][j].getState().sT == stateType::whiteCheck){
                                    theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::bothCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                                } else {
                                    theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::blackCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                                }
                            } else {
                                break;
                            }
                            nextmoves.emplace_back(nextP);
                        }
                    }
                } else {
                    if(j + next[k].colChange < 8 && i + next[k].rowChange < 8 && i + next[k].rowChange > -1 && j + next[k].colChange > -1){
                        Position nextP{j + next[k].colChange, i + next[k].rowChange};
                        if(theBoard[i][j].getColour() == Colour::White){
                            if(theBoard[i + next[k].rowChange][j + next[k].colChange].getState().sT == stateType::blackCheck){ // blackCheck is the piece where black piece can check
                                theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::bothCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                            } else{
                                theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::whiteCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                            }
                        } else if(theBoard[i][j].getColour() == Colour::Black) {
                            if(theBoard[i + next[k].rowChange][j].getState().sT == stateType::whiteCheck){
                                theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::bothCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                            } else {
                                theBoard[i + next[k].rowChange][j + next[k].colChange].setState(stateType::blackCheck, theBoard[i + next[k].rowChange][j + next[k].colChange].getState().colour);
                            }
                        }
                        nextmoves.emplace_back(nextP);
                    }
                }
            }
        }
    }
    return nextmoves;
} //allPossibleMove

bool Board::isStalemate(){
    if(theBoard[whiteK.row][whiteK.col].getState().sT == stateType::Nothing || theBoard[whiteK.row][whiteK.col].getState().sT == stateType::blackCheck){
        return allPossibleMoves().empty();
    } else if(theBoard[blackK.row][blackK.col].getState().sT == stateType::Nothing || theBoard[blackK.row][blackK.col].getState().sT == stateType::whiteCheck){
        return allPossibleMoves().empty();
    }
    return false;
} //isStalemate

vector<Position> Board::getNextMove(string startPos){ //return next move for chosen piece's pieceType
    vector<Position> nextPos;
    vector intStartPos = intPos(startPos);
    int startr = intStartPos[1];
    int startc= intStartPos[0];
    vector<moveType> movetypes = theBoard[startr][startc].getMoveType();
    if(movetypes[0].repeatable){
        for(size_t j = 0; j < movetypes.size(); ++j){
            moveType tempMT = movetypes[j];
            for(int i = 1; i < BOARD_SIZE + 1; ++i){
                int tempR = startr + i*tempMT.rowChange;
                int tempC = startc + i*tempMT.colChange;
                if(tempR < 8 && tempC < 8 && tempR >= 0 && tempC >= 0){
                    Position next{tempC, tempR};
                    nextPos.emplace_back(next);
                }
            }
        }
    } else {
        for(size_t j = 0; j < movetypes.size(); ++j){
            moveType tempMT = movetypes[j];
            int tempR = startr + tempMT.rowChange;
            int tempC = startc + tempMT.colChange;
            if(tempR < 8 && tempC < 8 && tempR >= 0 && tempC >= 0){
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
    if(theBoard[wR][wC].getState().sT == stateType::whiteCheck || theBoard[wR][wC].getState().sT == stateType::bothCheck){
        if(theBoard[bR][bC].getState().sT == stateType::blackCheck || theBoard[bR][bC].getState().sT == stateType::bothCheck){
            return "both";
        } else{
            return "white";
        }
    } else if(theBoard[bR][bC].getState().sT == stateType::blackCheck || theBoard[bR][bC].getState().sT == stateType::bothCheck){
        if(theBoard[wR][wC].getState().sT == stateType::whiteCheck || theBoard[wR][wC].getState().sT == stateType::bothCheck){
            return "both";
        } else{
            return "black";
        }
    } else {
        return "nothing";
    }
} //isInCheck

bool Board::whiteKingCanMove() {
    vector<Position> nextW = theBoard[whiteK.row][whiteK.col].nextMove();
    for(size_t i = 0; i < nextW.size(); ++i) {
        int r = whiteK.row + nextW[i].row;
        int c = whiteK.col + nextW[i].col;
        if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE) continue;

        Piece &nextMove = theBoard[r][c];  // Use reference to avoid copying
        if (nextMove.getColour() == Colour::White
            || nextMove.getState().sT == stateType::whiteCheck
            || nextMove.getState().sT == stateType::bothCheck) {
            return false;
        }
    }
    return true;
} // whiteKingCanMove

bool Board::blackKingCanMove() {
    vector<Position> nextB = theBoard[blackK.row][blackK.col].nextMove();
    for(size_t i = 0; i < nextB.size(); ++i) {
        int r = blackK.row + nextB[i].row;
        int c = blackK.col + nextB[i].col;
        if (r < 0 || r >= BOARD_SIZE || c < 0 || c >= BOARD_SIZE) continue;

        Piece &nextMove = theBoard[r][c];  // Use reference
        if (nextMove.getColour() == Colour::Black
            || nextMove.getState().sT == stateType::blackCheck
            || nextMove.getState().sT == stateType::bothCheck) {
            return false;
        }
    }
    return true;
} // blackKingCanMove

// allow a single undo
void Board::undo() {
    // check if there is previous move
    if (prev.isEmpty) {
        cerr << "There is no previous action" << endl; 
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
} //undo

ostream &operator<<(ostream &out, const Board &b) {
    if(b.td) out << *(b.td);
    return out;
}
