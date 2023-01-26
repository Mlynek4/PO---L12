#include "../../include/CliChess/Knight.hpp"

Knight::Knight(PieceColor color): Piece(color) {}

char Knight::letter_symbol() const {
    return this->Color() == PieceColor::White ? 'N' : 'n';
}

PieceId Knight::id() const {
    return PieceId::Knight;
}

std::vector<std::pair<int, int>> Knight::possible_moves(std::pair<int, int> my_position, Board current_board) const {

    std::vector<std::pair<int, int>> possible_moves;
    int x = my_position.first;
    int y = my_position.second;

    // Up
    if (y + 2 < 8) {
        if (x + 1 < 8) {
            if (current_board.piece_at({x + 1, y + 2}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + 1, y + 2));
            } else {
                if (current_board.piece_at({x + 1, y + 2})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x + 1, y + 2));
                }
            }
        }
        if (x - 1 >= 0) {
            if (current_board.piece_at({x - 1, y + 2}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - 1, y + 2));
            } else {
                if (current_board.piece_at({x - 1, y + 2})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x - 1, y + 2));
                }
            }
        }
    }

    // Down
    if (y - 2 >= 0) {
        if (x + 1 < 8) {
            if (current_board.piece_at({x + 1, y - 2}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + 1, y - 2));
            } else {
                if (current_board.piece_at({x + 1, y - 2})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x + 1, y - 2));
                }
            }
        }
        if (x - 1 >= 0) {
            if (current_board.piece_at({x - 1, y - 2}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - 1, y - 2));
            } else {
                if (current_board.piece_at({x - 1, y - 2})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x - 1, y - 2));
                }
            }
        }
    }

    // Left
    if (x - 2 >= 0) {
        if (y + 1 < 8) {
            if (current_board.piece_at({x - 2, y + 1}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - 2, y + 1));
            } else {
                if (current_board.piece_at({x - 2, y + 1})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x - 2, y + 1));
                }
            }
        }
        if (y - 1 >= 0) {
            if (current_board.piece_at({x - 2, y - 1}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - 2, y - 1));
            } else {
                if (current_board.piece_at({x - 2, y - 1})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x - 2, y - 1));
                }
            }
        }
    }

    // Right
    if (x + 2 < 8) {
        if (y + 1 < 8) {
            if (current_board.piece_at({x + 2, y + 1}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + 2, y + 1));
            } else {
                if (current_board.piece_at({x + 2, y + 1})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x + 2, y + 1));
                }
            }
        }
        if (y - 1 >= 0) {
            if (current_board.piece_at({x + 2, y - 1}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + 2, y - 1));
            } else {
                if (current_board.piece_at({x + 2, y - 1})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x + 2, y - 1));
                }
            }
        }
    }


    return possible_moves;
}