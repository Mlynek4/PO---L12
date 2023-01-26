#ifndef _CLI_CHESS_COMMON_HPP_
#define _CLI_CHESS_COMMON_HPP_

enum class PieceId { Pawn, Rook , Knight, Bishop, Queen, King };
enum class PieceColor{ White, Black };
enum class MoveResult{ IllegalMove , NoPiece, KingInCheck, Draw, Checkmate, MoveMade};

class Piece;
class Board;

#endif