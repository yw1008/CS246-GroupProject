#include "piece.h"
#include "board.h"
#include <string>
#include <vector>

using namespace std;

pieceType Piece::getType() {
    if(type == 'p' || type == 'P'){
        return pieceType::Pawn;
    } else if(type == 'r' || type == 'R'){
        return pieceType::Rook;
    } else if(type == 'n' || type == 'N'){
        return pieceType::Knight;
    } else if(type == 'b' || type == 'B'){
        return pieceType::Bishop;
    } else if(type == 'k' || type == 'K'){
        return pieceType::King;
    } else if(type == 'q' || type == 'Q'){
        return pieceType::Queen;
    } else if(type == ' '){
        return pieceType::White;
    } else {
        return pieceType::Black;
    }
}

bool isValid(const string &to, const Board &b){ //Check the board there is no any piece on the "to" position and the end position is on the board
    vector<int> to = Board::intPos(to);
    int col = to[0];
    int row = to[1];

    Piece endpoint = b.theBoard[r][c]; // need to check the order of row and column
    
    if(to[0] > 8 || to[1] > 8){
        return false;
    } else if(to[0] < 0 || to[1] < 0){
        return false;
    } else if(endpoint.type == ' ' || endpoint.type == '_'){
        return true;
    } else {
        return false
    }
}
