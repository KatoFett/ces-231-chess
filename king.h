#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;
class Rook;

class King : public Piece
{
public:

   King(Square* square, Player& player)
      : Piece(square, player)
   {}

   static const char NAME; // The name of the piece.

   const Move* getMoveFromSquare(Square* destination) override; // Returns a castle move if they are possible.
   set<Square*> getMoves() const override; // Gets all possible moves of the king.
   set<Square*> getCastleMoves() const; // Gets all possible castle moves.
   const char getName() const override { return NAME; } // Returns the name of the piece.
   Rook* getLeftCastleRook() const; // Determines if we can castle to the left.
   Rook* getRightCastleRook() const; // Determines if we can castle to the right
};