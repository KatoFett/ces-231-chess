#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;
class Player;

class Rook : public Piece
{
public:
   Rook(Square* square, Player& player)
      : Piece(square, player)
   {}

   static const char* NAME;

   const char* getName() const override { return NAME; }
   set<Square*> getMoves() const override { return getRookMoves(this->square); };
   static set<Square*> getRookMoves(Square* square);
};

