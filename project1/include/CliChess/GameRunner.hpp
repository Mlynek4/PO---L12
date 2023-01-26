#ifndef _CLI_CHESS_GAME_RUNNER_HPP_
#define _CLI_CHESS_GAME_RUNNER_HPP_

#include "Board.hpp"
#include "common.hpp"

class GameRunner final {
    Board* current_board;
    PieceColor on_move;
public:
    GameRunner();
    void restart();
    void start_from_position(Board board);
    
    MoveResult make_move(std::pair<int, int> from, std::pair<int, int> to);
    void pass_move();
    void print_currnet_board();
    void possible_moves_for_piece(std::pair<int, int> position);
    PieceColor color_on_move() const;

    ~GameRunner();
};

#endif