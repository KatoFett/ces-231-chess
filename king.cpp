#include "king.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "rook.h"
#include "player.h"
#include <set>

const char King::NAME = 'K';

set<Square*> King::getMoves() const
{
   /*
      {-1,  1}, {0,  1},  {1,  1},
      {-1,  0},          {1,  0},
      {-1, -1}, {0, -1}, {1, -1}
   */

   set<Square*> moves;

   Player& player = square->getPiece()->getPlayer();


   int cols[] = { -1, 0, 1 };
   int rows[] = { -1, 0, 1 };
   for (int col : cols)
   {
      for (int row : rows)
      {
         Square* destination = square->getAdjacent(col, row);
         if (canMoveToSquare(player, destination)) moves.insert(destination);
      }
   }

   // This will give us moves if castling is possible.
   set<Square*> castleMoves = getCastleMoves();

   for each (Square * move in castleMoves)
   {
      moves.insert(move);
   }

   return moves;
}

set<Square*> King::getCastleMoves() const
{
   set<Square*> moves;
   Direction direction = player.getDirection();

   if (!hasMoved)
   {
      // Check left rook.
      Rook* castleRook = getLeftCastleRook();
      if (castleRook != nullptr)
      {
         // This is where the king will end up.
         moves.insert(square->getLeft(direction)->getLeft(direction));
      }

      // Check right rook.
      castleRook = getRightCastleRook();
      if (castleRook != nullptr)
      {
         //This is where the king will end up.
         moves.insert(square->getRight(direction)->getRight(direction));
      }
   }

   return moves;
}

Rook* King::getLeftCastleRook() const
{
   const Direction direction = player.getDirection();
   Square* rookSquare = square->getLeft(direction);
   while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
   {
      rookSquare = rookSquare->getLeft(direction);
   }

   if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
      return (Rook*)rookSquare->getPiece();

   return nullptr;
}

Rook* King::getRightCastleRook() const
{
   const Direction direction = player.getDirection();
   Square* rookSquare = square->getRight(direction);
   while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
   {
      rookSquare = rookSquare->getRight(direction);
   }

   if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
      return (Rook*)rookSquare->getPiece();

   return nullptr;
}

const Move* King::getMoveFromSquare(Square* destination)
{
   // Check if it's a castle square.
   if (!hasMoved)
   {
      const Direction direction = player.getDirection();
      int dCol = destination->getCol() - square->getCol();
      int dRow = destination->getRow() - square->getRow();
      bool isCastling = max(abs(dCol), abs(dRow)) > 1;
      if (isCastling)
      {
         // Short castling is determined if the rook is immediately adjacent
         // to the castling square. Otherwise, it's a long castle.
         bool isShortCastle = false;
         Square* rookSquare = destination->getLeft(direction);
         if (rookSquare != nullptr && rookSquare->getPiece() != nullptr)
            isShortCastle = true;
         else
         {
            rookSquare = destination->getRight(direction);
            if (rookSquare != nullptr && rookSquare->getPiece() != nullptr)
               isShortCastle = true;
         }

         return new Move(square, destination, this, isShortCastle ? CASTLE : CASTLE_LONG);
      }
   }

   return Piece::getMoveFromSquare(destination);
}