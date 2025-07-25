#include "computer.h"
#include "board.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <memory>

Computer::Computer(bool isWhite, int lvl) : Player(isWhite, lvl) {}

//Computer::~Computer() = default;

int Computer::getLevel() const {
    return Player::getLevel();
}

bool Computer::isValid(string &startPos, string &endPos, Board *board) {
    // need to check if the move make player him/herself check
    int startr, startc, endr, endc;

    try {
        vector<int> intStartPos = board->intPos(startPos);
        startc = intStartPos[0];
        startr = intStartPos[1];
    } catch (const invalid_argument& e) {
        return false;
    }

    try {
        vector<int> intEndPos = board->intPos(endPos);
        endc = intEndPos[0];
        endr = intEndPos[1];
    } catch (const invalid_argument& e) {
        return false;
    }

    Colour c;
    if (Player::isWhite()) c = Colour::White;
    else c = Colour::Black;

    if (board->getBoard()[startr][startc].getColour() != c) {
        return false;
    }
    Position toPos{endc, endr};

    Position diffPos;
    diffPos.col = endc - startc;
    diffPos.row = endr - startr;
    vector<moveType> possibleMove = board->getBoard()[startr][startc].getMoveType();
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
        
        for (size_t j = 1; j < 9; ++j) {
            int tempc = correctMove.colChange * j + startc;
            int tempr = correctMove.rowChange * j + startr;
            if (tempc < 0 || tempc >= 8 ||
                tempr < 0 || tempr >= 8) break;

            if (tempc == endc && tempr == endr) break; // escape if the loop gets to the end posisiton
            
            if (board->getBoard()[tempr][tempc].getPieceType() != pieceType::Nothing) {
                return false;
            }
        } 
    }

    if (board->getBoard()[endr][endc].getPieceType() != pieceType::Nothing) {
        // catching the same coloured piece
        if (board->getBoard()[endr][endc].getColour() == c) {
            return false;
        }
    }
    return true;
}

void Computer::move(std::string &startPos, std::string &endPos, Board *board) {
    if(getLevel() == 1){
        moveLevel1(board);
    // } else if(getLevel() == 2){

    // }else if(getLevel() == 3){

    // }else {
        
    }
}

// Level 1
void Computer::moveLevel1(Board *board) {
    while(true){
        std::srand(std::time(nullptr));
        bool isWhite = Player::isWhite();
        int fromC = 0;
        int fromR = 0;
        int toC = 0;
        int toR = 0;
        int randomPick = 0;

        std::vector<std::vector<Piece>> current = board->getBoard();
        for (int attempts = 0; attempts < 500; ++attempts) {
            int vecSize = current.size();
            int randomPickC = std::rand() % vecSize;
            int randomPickR = std::rand() % vecSize;
            Piece picked = current[randomPickR][randomPickC];
            if(isWhite){
                if(picked.getColour() == Colour::White && !picked.getMoveType().empty()){
                    int fromC = picked.getInfo().pos.col;
                    int fromR = picked.getInfo().pos.row;
                    break;
                }
            } else{
                if(picked.getColour() == Colour::Black && !picked.getMoveType().empty()){
                    int fromC = picked.getInfo().pos.col;
                    int fromR = picked.getInfo().pos.row;
                    break;
                }
            }
        }
        char from[] = "  ";
        from[0] = 'a' + fromC;
        from[1] = '1' + fromR;
        std::string sFrom(from);

        if(board->getBoard()[fromR][fromC].getMoveType()[0].repeatable){
            std::vector<Position> nextmove = board->getNextMove(sFrom);
            int size = nextmove.size();
            randomPick = std::rand() % size;
            Position nextP = nextmove[randomPick];
            toC = nextP.col;
            toR = nextP.row;
        } else{
            std::vector<moveType> notrepeatable = board->getBoard()[fromR][fromC].getMoveType();
            int size = notrepeatable.size();
            randomPick = std::rand() % size;
            moveType pickedMT = notrepeatable[randomPick];
            toC = fromC + pickedMT.colChange;
            toR = fromR + pickedMT.rowChange;
        }
        char to[] = "  ";
        to[0] = 'a' + toC;
        to[1] = '1' + toR;
        std::string sTo(to);
        if(isValid(sFrom, sTo, board)){
            board->makeMove(sFrom, sTo);
            std::cout << "Computer (Level 1) moves: " << sFrom << " " << sTo << std::endl;
            break;
        } else {
            continue;
        }
    }
}

/*
// Level 2
void Computer::moveLevel2(Board &board) {
    std::srand(std::time(nullptr));

    for (int attempts = 0; attempts < 500; ++attempts) {
        int r1 = std::rand() % 8;
        int c1 = std::rand() % 8;
        int r2 = std::rand() % 8;
        int c2 = std::rand() % 8;

        std::string from = std::string(1, 'a' + c1) + std::to_string(8 - r1);
        std::string to = std::string(1, 'a' + c2) + std::to_string(8 - r2);

        char piece = board.getPiece(from);
        char target = board.getPiece(to);

        if (piece == ' ' || piece == '_') {
            continue;
        }
        if (from == to) {
            continue;
        }

        bool isCapture = (target != ' ' && target != '_');
        bool opponentPiece = (isWhite() && islower(target)) || (!isWhite() && isupper(target));

        if (isCapture && opponentPiece) {
            board.removePiece(to);
            board.addPiece(piece, to);
            board.removePiece(from);
            board.changeTurn();

            std::cout << "Computer (Level 2) captures: " << from << " " << to << std::endl;
            return;
        }
    }

    std::cout << "No captures or checks — falling back to Level 1...\n";
    moveLevel1(board);
}

// Level 3
void Computer::moveLevel3(Board &board) {
    std::srand(std::time(nullptr));

    for (int attempts = 0; attempts < 500; ++attempts) {
        int r1 = std::rand() % 8;
        int c1 = std::rand() % 8;
        int r2 = std::rand() % 8;
        int c2 = std::rand() % 8;

        std::string from = std::string(1, 'a' + c1) + std::to_string(8 - r1);
        std::string to = std::string(1, 'a' + c2) + std::to_string(8 - r2);

        char piece = board.getPiece(from);
        char target = board.getPiece(to);

        if (piece == ' ' || piece == '_') {
            continue;
        }
        if (from == to) {
            continue;
        }

        bool opponentPiece = (isWhite() && islower(target)) || (!isWhite() && isupper(target));
        bool isCapture = target != ' ' && target != '_';
        bool isSafe = true;

        if (isSafe && opponentPiece) {
            board.removePiece(to);
            board.addPiece(piece, to);
            board.removePiece(from);
            board.changeTurn();

            std::cout << "Computer (Level 3) safely captures: " << from << " " << to << std::endl;
            return;
        }
    }

    std::cout << "No safe captures — falling back to Level 2...\n";
    moveLevel2(board);
}
*/
