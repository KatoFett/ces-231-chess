#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;
class Player;

class Queen : public Piece
{
public:
   Queen(Square& square, Player& player)
      : Piece(square, player)
   {}

   static const char* NAME;

   const char* getName() const override { return NAME; }
   set<Square> getMoves() const override;

};

