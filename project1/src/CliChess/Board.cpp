#include "../../include/CliChess/Board.hpp"
#include"..//..//include/CliChess/Piece.hpp"
#include"..//..//include/CliChess/Pieces.hpp"


// Path: src\CliChess\Board.cpp

#include <iostream>
#include <algorithm>
#include <windows.h>  

using namespace std;

void Board::print_board(){
    cout << " -------------------------------" << endl;
    for (int i = 7; i >= 0; i--){
        //cout << i + 1 << " |";
        cout << i << " |";
        
        for (int j = 0; j < 8; j++){
            if (board[i][j] == nullptr){
                cout << "   |";
            }
            else{
                cout << " " << board[i][j]->letter_symbol() << " |";
            }
        }
        cout << endl;
    }
    cout << " /--0-|-1-|-2-|-3-|-4-|-5-|-6-|-7-/" << endl;
    // cout << " /--a-|-b-|-c-|-d-|-e-|-f-|-g-|-h-/" << endl;

}

void Board::move_piece(std::pair<int, int> from, std::pair<int, int> to){
    can_en_passant = false;

    if (board[from.first][from.second]->id() == PieceId::Pawn){
        
        // set up for en passant
        if (from.first - to.first == 2  || from.first - to.first == -2){
            can_en_passant = true;
            en_passant_position = to;
        }

        // check for en passant capture
        if (board[to.first][to.second] == nullptr && to.second != from.second){
            
            std::cout << "en passant capture" << std::endl;
        
            delete board[from.first][to.second];
            board[from.first][to.second] = nullptr;

        }
    }

    // clean up the old position
    if (board[to.first][to.second] != nullptr){
        delete board[to.first][to.second];
    }

    board[to.first][to.second] = std::move(board[from.first][from.second]);
    board[from.first][from.second] = nullptr;
    
}

void Board::add_piece(Piece* piece, std::pair<int, int> position){
    board[position.first][position.second] = piece;
}

void Board::remove_piece(std::pair<int, int> position){
    if (board[position.first][position.second] == nullptr){
        return;
    }
    
    delete board[position.first][position.second];
    board[position.first][position.second] = nullptr;
}

Piece* Board::piece_at(std::pair<int, int> position){
    return board[position.first][position.second];
}

bool Board::en_passant() const {
    return can_en_passant;
}

std::pair<int, int> Board::en_passant_square() const{
    return en_passant_position;
}


Board::Board(){
    board = std::vector<std::vector<Piece*>>(8, std::vector<Piece*>(8, nullptr));
    can_en_passant = false;
    en_passant_position = std::make_pair(-1, -1);
}

void Board::mark_possible_moves(std::pair<int, int> position){
    if (board[position.first][position.second] == nullptr){
        return;
    }

    auto moves = board[position.first][position.second]->possible_moves(position, *this);
    sort(moves.begin(), moves.end());
    cout << " -------------------------------" << endl;

    for (int i = 7; i >= 0; i--){
        cout << i << " |";        
        for (int j = 0; j < 8; j++){
            // there is a piece at this position
            if (board[i][j] != nullptr){
                // is it in the list of possible moves and can be taken?
                if (find(moves.begin(), moves.end(), std::pair<int, int>(i, j)) != moves.end()
                    && board[i][j]->Color() != board[position.first][position.second]->Color()){
                    cout << " " << "\033[1;31m"<< board[i][j]->letter_symbol() <<"\033[0m" << " |";
                }
                
                // is it the moving piece
                else if (i == position.first && j == position.second){
                    cout << " " << "\033[1;32m"<< board[i][j]->letter_symbol() <<"\033[0m" << " |";
                }                

                else {
                    cout << " " << board[i][j]->letter_symbol() << " |";
                }
            }

            else if (find(moves.begin(), moves.end(), std::pair<int, int>(i, j)) != moves.end()){
                cout << " * |";
            }
            else{
                cout << "   |";
            }
        }
        cout << endl;

    }
    cout << " /--0-|-1-|-2-|-3-|-4-|-5-|-6-|-7-/" << endl;
}

void Board::clear_board(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            this->remove_piece({i, j});
        }
    }
}

void Board::initalize_start_position(){
    // delete previous board
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            this->remove_piece({i, j});
        }
    }

    // White pieces
    add_piece(new Rook (PieceColor::White), {0, 0});
    add_piece(new Knight (PieceColor::White), {0, 1});
    add_piece(new Bishop (PieceColor::White), {0, 2});
    add_piece(new Queen (PieceColor::White), {0, 3});
    add_piece(new King (PieceColor::White), {0, 4});
    add_piece(new Bishop (PieceColor::White), {0, 5});
    add_piece(new Knight (PieceColor::White), {0, 6});
    add_piece(new Rook (PieceColor::White), {0, 7});
    for (int i = 0; i < 8; i++){
        add_piece(new Pawn (PieceColor::White), {1, i});
    }

    // Black pieces
    add_piece(new Rook (PieceColor::Black), {7, 0});
    add_piece(new Knight (PieceColor::Black), {7, 1});
    add_piece(new Bishop (PieceColor::Black), {7, 2});
    add_piece(new Queen (PieceColor::Black), {7, 3});
    add_piece(new King (PieceColor::Black), {7, 4});
    add_piece(new Bishop (PieceColor::Black), {7, 5});
    add_piece(new Knight (PieceColor::Black), {7, 6});
    add_piece(new Rook (PieceColor::Black), {7, 7});
    for (int i = 0; i < 8; i++){
        add_piece(new Pawn (PieceColor::Black), {6, i});
    }
}