#ifndef _CLI_CHESS_ROOK_HPP_
#define _CLI_CHESS_ROOK_HPP_

#include "Piece.hpp"

class Rook : public Piece {
public:
    Rook(PieceColor color);

    std::vector<std::pair<int, int>> possible_moves(std::pair<int, int> my_possition, Board currnet_board) const override;
    PieceId id() const override;
    char letter_symbol() const override;

};

#endif