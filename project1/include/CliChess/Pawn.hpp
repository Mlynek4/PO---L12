#ifndef _CLICHESS_PAWN_HPP_
#define _CLICHESS_PAWN_HPP_

#include "Piece.hpp"

class Pawn final : public Piece {
public:
    Pawn(PieceColor color);

    std::vector<std::pair<int, int>> possible_moves(std::pair<int, int> my_possition, Board currnet_board) const override;
    PieceId id() const override;
    char letter_symbol() const override;

};

#endif