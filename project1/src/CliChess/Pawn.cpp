#include "../../include/CliChess/Pawn.hpp"
#include <iostream>


Pawn::Pawn(PieceColor color): Piece(color) {}

char Pawn::letter_symbol() const {
    return this->Color() == PieceColor::White ? 'I' : 'i';
}

PieceId Pawn::id() const {
    return PieceId::Pawn;
}

using namespace std;

std::vector<std::pair<int, int>> Pawn::possible_moves(std::pair<int, int> my_position, Board current_board) const {
    std::vector<std::pair<int, int>> possible_moves;
    int x = my_position.first;
    int y = my_position.second;

    // move forward
    if (this->Color() == PieceColor::White) {
        if (x == 1) {
            if (current_board.piece_at({x + 1, y}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + 1, y));
                if (current_board.piece_at({x + 2, y}) == nullptr) {
                    possible_moves.push_back(std::make_pair(x + 2, y));
                }
            }
        } else {
            if (current_board.piece_at({x + 1, y}) == nullptr) {
                possible_moves.push_back(std::make_pair(x + 1, y));
            }
        }
    // black
    } else {
        if (x == 6) {
            if (current_board.piece_at({x - 1, y}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - 1, y));
                if (current_board.piece_at({x - 2, y}) == nullptr) {
                    possible_moves.push_back(std::make_pair(x - 2, y));
                }
            }
        } else {
            if (current_board.piece_at({x - 1, y}) == nullptr) {
                possible_moves.push_back(std::make_pair(x - 1, y));
            }
        }
    }

    // capture

    // left
    if (y > 0) {
        if (this->Color() == PieceColor::White) {
            if (current_board.piece_at({x + 1, y - 1}) != nullptr) {
                if (current_board.piece_at({x + 1, y - 1})->Color() == PieceColor::Black) {
                    possible_moves.push_back(std::make_pair(x + 1, y - 1));
                }
            }
        } else { // black
            if (current_board.piece_at({x - 1, y - 1}) != nullptr) {
                if (current_board.piece_at({x - 1, y - 1})->Color() == PieceColor::White) {
                    possible_moves.push_back(std::make_pair(x - 1, y - 1));
                }
            }
        }
    }

    // right
    if (y < 7) {
        if (this->Color() == PieceColor::White) {
            if (current_board.piece_at({x + 1, y + 1}) != nullptr) {
                if (current_board.piece_at({x + 1, y + 1})->Color() == PieceColor::Black) {
                    possible_moves.push_back(std::make_pair(x + 1, y + 1));
                }
            }
        } else { // black
            if (current_board.piece_at({x - 1, y + 1}) != nullptr) {
                if (current_board.piece_at({x - 1, y + 1})->Color() == PieceColor::White) {
                    possible_moves.push_back(std::make_pair(x - 1, y + 1));
                }
            }
        }
    }

    // en passant
    if (!current_board.en_passant()){
        return possible_moves;
    }
    
    // check for en passant
    auto en_passant_square = current_board.en_passant_square();
    std::pair<int, int> out_pair;

    if (en_passant_square.first != x) {
        return possible_moves;
    }

    if (en_passant_square.second == y - 1) {
        
        if (this->Color() == PieceColor::White) {
             possible_moves.push_back(std::make_pair(x + 1, y - 1));
        } else { // black
             possible_moves.push_back(std::make_pair(x - 1, y - 1));
        }
        

    } else if (en_passant_square.second == y + 1) {
       
        if (this->Color() == PieceColor::White) {
             possible_moves.push_back(std::make_pair(x + 1, y + 1));
        } else { // black
             possible_moves.push_back(std::make_pair(x - 1, y + 1));
        }
        

    }


    return possible_moves;
}