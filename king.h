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

   static const char NAME;

   const Move* getMoveFromSquare(Square* destination) override;
   set<Square*> getMoves() const override;
   set<Square*> getCastleMoves() const;
   const char getName() const override { return NAME; }
   Rook* getLeftCastleRook() const;
   Rook* getRightCastleRook() const;
};