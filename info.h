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

class Info {
    pieceType pieceType;
    Colour colour;
    Position pos;   
};

#endif
