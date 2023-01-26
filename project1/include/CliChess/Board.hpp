#ifndef _CLI_CHESS_BOARD_HPP_
#define _CLI_CHESS_BOARD_HPP_

#include <vector>
#include <memory>

#include "Piece.hpp"

class Board {
private:
    std::vector<std::vector<Piece*>> board;
    bool can_en_passant;
    std::pair<int, int> en_passant_position;
public:
    Board();
    void print_board();
    void move_piece(std::pair<int, int> from, std::pair<int, int> to);
    void add_piece(Piece* piece, std::pair<int, int> position);
    void remove_piece(std::pair<int, int> position);
    Piece* piece_at(std::pair<int, int> position);
    void initalize_start_position();
    void mark_possible_moves(std::pair<int, int> position);
    void clear_board();
    bool en_passant() const;
    std::pair<int, int> en_passant_square() const;
};

#endif