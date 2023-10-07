#pragma once

#include "square.h"
#include "player.h"

class Piece
{
protected:
   Player& player;
   Square& square;
   bool hasMoved;

public:

   Piece(Square& square, Player& player) :
      square(square), player(player)
   {}

   Square& getSquare() const { return square; }
   Player& getPlayer() const { return player; }
   bool getHasMoved() const { return hasMoved; }
   virtual const char* getName() const = 0;
   virtual set<Square> getMoves() const;
};


