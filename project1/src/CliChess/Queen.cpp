#include "../../include/CliChess/Queen.hpp"

Queen::Queen(PieceColor color): Piece(color) {}

char Queen::letter_symbol() const {
    return this->Color() == PieceColor::White ? 'Q' : 'q';
}

PieceId Queen::id() const {
    return PieceId::Queen;
}

std::vector<std::pair<int, int>> Queen::possible_moves(std::pair<int, int> my_position, Board current_board) const {
    
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

    // Up Right
    for (int i = 1; i < 8; i++) {
        if (x + i < 8 && y + i < 8) {
            if (current_board.piece_at({x + i, y + i}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + i, y + i));
            } else {
                if (current_board.piece_at({x + i, y + i})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x + i, y + i));
                }
                break;
            }
        }
    }

    // Up Left
    for (int i = 1; i < 8; i++) {
        if (x - i >= 0 && y + i < 8) {
            if (current_board.piece_at({x - i, y + i}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - i, y + i));
            } else {
                if (current_board.piece_at({x - i, y + i})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x - i, y + i));
                }
                break;
            }
        }
    }

    // Down Right
    for (int i = 1; i < 8; i++) {
        if (x + i < 8 && y - i >= 0) {
            if (current_board.piece_at({x + i, y - i}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + i, y - i));
            } else {
                if (current_board.piece_at({x + i, y - i})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x + i, y - i));
                }
                break;
            }
        }
    }

    // Down Left
    for (int i = 1; i < 8; i++) {
        if (x - i >= 0 && y - i >= 0) {
            if (current_board.piece_at({x - i, y - i}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - i, y - i));
            } else {
                if (current_board.piece_at({x - i, y - i})->Color() != this->Color()) {
                    possible_moves.push_back(std::make_pair(x - i, y - i));
                }
                break;
            }
        }
    }

    return possible_moves;
}
