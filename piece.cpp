#include "piece.h"
#include "square.h"
#include "player.h"
#include "move.h"

Piece::Piece(Square* square, Player& player) :
   square(square), player(player), hasMoved(false)
{
   this->square->setPiece(this);
   player.addPiece(this);
}

Move* Piece::moveToSquare(Square* destination)
{
   Move* move = getMoveFromSquare(destination);

   // Set this square to empty.
   square->setPiece(nullptr);

   // Capture piece.
   Piece* captured = destination->getPiece();
   if (captured != nullptr)
      captured->player.removePiece(captured);

   // Move to the square.
   square = destination;
   destination->setPiece(this);

   return move;
}

Move* Piece::getMoveFromSquare(Square* destination)
{
   Move* move = new Move(square, destination, this, destination->getPiece());
   return move;
}

bool Piece::canMoveToSquare(Player& player, Square* destination)
{
   return destination != nullptr && (destination->getPiece() == nullptr || destination->getPiece()->player != player);
}
