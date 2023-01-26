#include "../../include/CliChess/Rook.hpp"

#include <iostream>

Rook::Rook(PieceColor color): Piece(color) {}

char Rook::letter_symbol() const {
    return this->Color() == PieceColor::White ? 'R' : 'r';
}

PieceId Rook::id() const {
    return PieceId::Rook;
}

std::vector<std::pair<int, int>> Rook::possible_moves(std::pair<int, int> my_position, Board current_board) const {
    std::vector<std::pair<int, int>> possible_moves;
    int x = my_position.first;
    int y = my_position.second;

     // Up
    for (int i = y + 1; i < 8; i++) {
        if (current_board.piece_at({x, i}) == nullptr) {
            possible_moves.push_back(std::make_pair(x, i));
        } else {
            if (current_board.piece_at({x, i})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x, i));
            }
            break;
        }
    }

    // Down
    for (int i = y - 1; i >= 0; i--) {
        if (current_board.piece_at({x, i}) == nullptr) {
            possible_moves.push_back(std::make_pair(x, i));
        } else {
            if (current_board.piece_at({x, i})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x, i));
            }
            break;
        }
    }

    // Right
    for (int i = x + 1; i < 8; i++) {
        if (current_board.piece_at({i, y}) == nullptr) {
            possible_moves.push_back(std::make_pair(i, y));
        } else {
            if (current_board.piece_at({i, y})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(i, y));
            }
            break;
        }
    }

    // Left
    for (int i = x - 1; i >= 0; i--) {
        if (current_board.piece_at({i, y}) == nullptr) {
            possible_moves.push_back(std::make_pair(i, y));
        } else {
            if (current_board.piece_at({i, y})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(i, y));
            }
            break;
        }
    }

    return possible_moves;
}

