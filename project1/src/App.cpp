#include "../include/CliChess/Pieces.hpp"
#include "../include/CliChess/Board.hpp"
#include "../include/CliChess/GameRunner.hpp"

#include <iostream>

using namespace std;

void game_loop(){
    cout << "Welcome to CliChess!" << endl;
    GameRunner gameRunner;
    gameRunner.restart();
    gameRunner.print_currnet_board();


    int from_x, from_y, to_x, to_y;
    while (true){
        cout << "Enter move: \n";
        cout << "From: ";        
        cin >> from_x >> from_y;
        gameRunner.possible_moves_for_piece({from_x, from_y});
        cout << "\nTo: ";
        cin >> to_x >> to_y;
        
        auto res = gameRunner.make_move({from_x, from_y}, {to_x, to_y});
        if (res != MoveResult::MoveMade) {
            cout << "Illegal move" << endl;
        }

        gameRunner.print_currnet_board();
    }
}

Board remove_pawns(Board &board) {
    for (int i = 0; i < 8; i++) {
        board.remove_piece({1, i});
        board.remove_piece({6, i});
    }
    return board;
}

void print_possible_moves(Board &board, std::pair<int, int> position) {
    if (board.piece_at(position) == nullptr) {
        std::cout << "No piece at (" << position.first << ", " << position.second << ")" << std::endl;
        return;
    }

    std::cout << "Possible moves for "<<
        (board.piece_at(position)->Color() == PieceColor::White ? "white" : "black") <<
        " " << board.piece_at(position)->letter_symbol() << 
        " at (" << position.first << ", " << position.second << "):" << std::endl;

    auto moves = board.piece_at(position)->possible_moves(position, board);
    for (auto move : moves) {
        std::cout << "(" << move.first << ", " << move.second << ")" << ", ";
    }
    cout << std::endl;
}

int main()
{

     game_loop();

   /*
     Board board;

    board.initalize_start_position();
    board.print_board();

    // print_possible_moves(board, {1, 0});
    board.move_piece({1, 5}, {4, 5});
    
    board.print_board();

    board.move_piece({6, 4}, {4, 4});
    
    board.mark_possible_moves({4, 5});

    board.move_piece({4, 5}, {5, 4});

    board.print_board();
    */
}