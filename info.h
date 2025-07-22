#ifndef INFO_H
#define INFO_H
#include <vector>
#include "state.h"

/* 

*/
enum class pieceType {Pawn, King, Queen, Rook, Knight, Bishop, Nothing};
enum class Colour {Nothing, White, Black};

struct Position{
    int col, row;
}; // We can use Postion to "Postion next{current.col + colChange, current.row + rowChange};" 

struct Info {
    pieceType piecetype;
    Colour colour;
    Position pos;   
};

#endif
