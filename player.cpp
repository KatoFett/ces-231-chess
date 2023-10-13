#include "player.h"
#include "piece.h"
#include "square.h"

void Player::removePiece(Piece* piece)
{
   pieces.erase(piece);
   if (piece->getSquare() != nullptr && piece->getSquare()->getPiece() == piece)
      piece->getSquare()->setPiece(nullptr);
}