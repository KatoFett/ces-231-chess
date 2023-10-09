#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;

class King : public Piece
{
public:

   King(Square* square, Player& player)
      : Piece(square, player)
   {}

   static const char* NAME;

   set<Square*> getMoves() const override;
   set<Square*> getCastleMoves() const;
   const char* getName() const override { return NAME; }
};