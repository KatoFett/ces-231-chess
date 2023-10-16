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

   static const char NAME;

   const char getName() const override { return NAME; } // Returns the name of the piece.
   set<Square*> getMoves() const override { return getRookMoves(this->square); }; // Returns the rooks possible moves.
   static set<Square*> getRookMoves(const Square* square); // Returns the rooks possible moves from a given square.
};

