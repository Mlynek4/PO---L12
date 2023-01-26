#include "../../include/CliChess/King.hpp"

King::King(PieceColor color): Piece(color) {}

char King::letter_symbol() const {
    return this->Color() == PieceColor::White ? 'K' : 'k';
}

PieceId King::id() const {
    return PieceId::King;
}

std::vector<std::pair<int, int>> King::possible_moves(std::pair<int, int> my_position, Board current_board) const {

    std::vector<std::pair<int, int>> possible_moves;
    int x = my_position.first;
    int y = my_position.second;

    // Up
    if (y + 1 < 8) {
        if (current_board.piece_at({x, y + 1}) == nullptr) {
            possible_moves.push_back(std::make_pair(x, y + 1));
        } else {
            if (current_board.piece_at({x, y + 1})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x, y + 1));
            }
        }
    }

    // Down
    if (y - 1 >= 0) {
        if (current_board.piece_at({x, y - 1}) == nullptr) {
            possible_moves.push_back(std::make_pair(x, y - 1));
        } else {
            if (current_board.piece_at({x, y - 1})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x, y - 1));
            }
        }
    }

    // Left
    if (x - 1 >= 0) {
        if (current_board.piece_at({x - 1, y}) == nullptr) {
            possible_moves.push_back(std::make_pair(x - 1, y));
        } else {
            if (current_board.piece_at({x - 1, y})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x - 1, y));
            }
        }
    }

    // Right
    if (x + 1 < 8) {
        if (current_board.piece_at({x + 1, y}) == nullptr) {
            possible_moves.push_back(std::make_pair(x + 1, y));
        } else {
            if (current_board.piece_at({x + 1, y})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x + 1, y));
            }
        }
    }

    // Up-Right
    if (x + 1 < 8 && y + 1 < 8) {
        if (current_board.piece_at({x + 1, y}) == nullptr) {
            possible_moves.push_back(std::make_pair(x + 1, y));
        } else {
            if (current_board.piece_at({x + 1, y})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x + 1, y));
            }
        }
    }

    // Up-Left
    if (x - 1 >= 0 && y + 1 < 8) {
        if (current_board.piece_at({x - 1, y + 1}) == nullptr) {
            possible_moves.push_back(std::make_pair(x - 1, y + 1));
        } else {
            if (current_board.piece_at({x - 1, y + 1})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x - 1, y + 1));
            }
        }
    }

    // Down-Right
    if (x + 1 < 8 && y - 1 >= 0) {
        if (current_board.piece_at({x + 1, y - 1}) == nullptr) {
            possible_moves.push_back(std::make_pair(x + 1, y - 1));
        } else {
            if (current_board.piece_at({x + 1, y - 1})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x + 1, y - 1));
            }
        }
    }

    // Down-Left
    if (x - 1 >= 0 && y - 1 >= 0) {
        if (current_board.piece_at({x - 1, y - 1}) == nullptr) {
            possible_moves.push_back(std::make_pair(x - 1, y - 1));
        } else {
            if (current_board.piece_at({x - 1, y - 1})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x - 1, y - 1));
            }
        }
    }


    return possible_moves;
}