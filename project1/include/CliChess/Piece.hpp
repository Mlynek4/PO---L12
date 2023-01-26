#ifndef _CLI_CHESS_PIECE_HPP_
#define _CLI_CHESS_PIECE_HPP_

#include <vector>
#include "common.hpp"
#include "board.hpp"

class Piece {
private:
    PieceColor my_color;

public:
    Piece(PieceColor color);
    virtual PieceColor Color() const;
    
    virtual std::vector<std::pair<int, int>> possible_moves(std::pair<int, int> my_possition, Board current_board) const = 0;
    virtual PieceId id() const = 0;
    virtual char letter_symbol() const = 0;

    virtual ~Piece() = default;
};

#endif