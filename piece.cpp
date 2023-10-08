#include "piece.h"
#include "square.h"
#include "player.h"

void Piece::moveToSquare(Square& newSquare)
{
   square.setPiece(nullptr);

   Piece* captured = newSquare.getPiece();
   if (captured != nullptr)
      captured->player.removePiece(captured);

   square = newSquare;
   newSquare.setPiece(this);
}