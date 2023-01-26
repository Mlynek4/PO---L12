#include "../../include/CliChess/Piece.hpp"
#include "../../include/CliChess/common.hpp"


Piece::Piece(PieceColor color): my_color(color) {}

PieceColor Piece::Color() const { 
    return my_color; 
}

