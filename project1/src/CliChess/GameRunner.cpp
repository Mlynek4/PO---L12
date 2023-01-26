#include "../../include/CliChess/GameRunner.hpp"

#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

GameRunner::GameRunner() {
    this->current_board = new Board();
    current_board->initalize_start_position();
    this->on_move = PieceColor::White;
}

GameRunner::~GameRunner() {
    delete current_board;
}

void GameRunner::restart() {
    this->current_board->initalize_start_position();
    this->on_move = PieceColor::White;
}

void GameRunner::start_from_position(Board board) {
    // clear the board
    this->current_board->clear_board();
    // copy the pieces from the given board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.piece_at({i, j}) == nullptr) 
                continue;

            this->current_board->add_piece(board.piece_at({i, j}), {i, j});
        }
    }

    this->on_move = PieceColor::White;
}

MoveResult GameRunner::make_move(std::pair<int, int> from, std::pair<int, int> to) {
    if (this->current_board->piece_at(from) == nullptr) {
        return MoveResult::NoPiece;
    }
    if (this->current_board->piece_at(from)->Color() != this->on_move) {
        return MoveResult::IllegalMove;
    }

    auto moves = this->current_board->piece_at(from)->possible_moves(from, *this->current_board);
    if (moves.size() == 0) {
        return MoveResult::IllegalMove;
    }
   
    if (std::find(moves.begin(), moves.end(), to) == moves.end()) {
        return MoveResult::IllegalMove;
    }

    //check for checks

    // TODO check for checkmate

    // make the move
    this->current_board->move_piece(from, to);
    pass_move();
    return MoveResult::MoveMade;
}


void GameRunner::pass_move() {
    this->on_move = this->on_move == PieceColor::White ? PieceColor::Black : PieceColor::White;
}

void GameRunner::print_currnet_board() {
    this->current_board->print_board();
}

void GameRunner::possible_moves_for_piece(std::pair<int, int> position) {
    current_board->mark_possible_moves(position);
}

PieceColor GameRunner::color_on_move() const {
    return this->on_move;
}
