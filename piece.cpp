#include "piece.h"
#include "square.h"
#include "player.h"
#include "move.h"

/*
* PIECE Constructor
* Creates a new piece, assigning it to the provided square and player.
*/
Piece::Piece(Square* square, Player& player) :
   square(square), player(player), hasMoved(false)
{
   this->square->setPiece(this);
   player.addPiece(this);
}

/*
* MOVE TO SQUARE
* Operation that moves the piece to the destination, and captures if possible.
*/
const Move* Piece::moveToSquare(Square* destination)
{
   const Move* move = getMoveFromSquare(destination);

   // Set this square to empty.
   square->setPiece(nullptr);

   // Capture piece.
   Piece* captured = move->getPieceCaptured();
   if (captured != nullptr)
      captured->player.removePiece(captured);

   // Move to the square.
   square = destination;
   destination->setPiece(this);

   hasMoved = true;

   return move;
}

/* 
* GET MOVE FROM SQUARE
* Creates a move that describes how the piece would move there.
* This method can be overridden for special moves (e.g. castling).
*/
const Move* Piece::getMoveFromSquare(Square* destination)
{
   const Move* move = new Move(square, destination, this, destination->getPiece());
   return move;
}

/*
* CAN MOVE TO SQUARE
* Returns whether the piece can move to the square, which is determined by:
* 1) The square exists, and
* 2) There is no piece on it, or the piece is another player's.
*/
bool Piece::canMoveToSquare(const Player& player, const Square* destination)
{
   return destination != nullptr && (destination->getPiece() == nullptr || destination->getPiece()->player != player);
}
