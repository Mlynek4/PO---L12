#include "../../include/CliChess/Bishop.hpp"

#include <iostream>

Bishop::Bishop(PieceColor color): Piece(color) {}

char Bishop::letter_symbol() const {
    return this->Color() == PieceColor::White ? 'B' : 'b';
}

PieceId Bishop::id() const {
    return PieceId::Bishop;
}

std::vector<std::pair<int, int>> Bishop::possible_moves(std::pair<int, int> my_position, Board current_board) const {

    std::vector<std::pair<int, int>> possible_moves;
    int x = my_position.first;
    int y = my_position.second;

    // Up-Right
    for (int i = 1; i < 8; i++) {
        if (x + i > 7 || y + i > 7) break;
        if (current_board.piece_at({x + i, y + i}) == nullptr) {
            possible_moves.push_back(std::make_pair(x + i, y + i));
        } else {
            if (current_board.piece_at({x + i, y + i})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x + i, y + i));
            }
            break;
        }
    }

    // Up-Left
    for (int i = 1; i < 8; i++) {
        if (x - i < 0 || y + i > 7) break;
        if (current_board.piece_at({x - i, y + i}) == nullptr) {
            possible_moves.push_back(std::make_pair(x - i, y + i));
        } else {
            if (current_board.piece_at({x - i, y + i})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x - i, y + i));
            }
            break;
        }
    }

    // Down-Right
    for (int i = 1; i < 8; i++) {
        if (x + i > 7 || y - i < 0) break;
        if (current_board.piece_at({x + i, y - i}) == nullptr) {
            possible_moves.push_back(std::make_pair(x + i, y - i));
        } else {
            if (current_board.piece_at({x + i, y - i})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x + i, y - i));
            }
            break;
        }
    }

    // Down-Left
    for (int i = 1; i < 8; i++) {
        if (x - i < 0 || y - i < 0) break;
        if (current_board.piece_at({x + i, y - i}) == nullptr) {
            possible_moves.push_back(std::make_pair(x + i, y - i));
        } else {
            if (current_board.piece_at({x + i, y - i})->Color() != this->Color()) {
                possible_moves.push_back(std::make_pair(x + i, y - i));
            }
            break;
        }
    }

    return possible_moves;
}




