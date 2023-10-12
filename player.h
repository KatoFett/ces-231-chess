#pragma once

#include <set>
#include <algorithm>
#include "direction.h"

using namespace std;

class Piece;

class Player
{
private:
   Direction direction;
   int color[3];
   set<Piece*> pieces;
public:
   Player(Direction direction, int color[3]) :
      direction(direction), color()
   {
      copy_n(color, 3, this->color);
   }

   bool operator == (const Player& rhs) const { return this == &rhs; }
   bool operator != (const Player& rhs) const { return this != &rhs; }

   bool hasPieces() const { return !pieces.empty(); }

   Direction getDirection() const { return direction; }
   int* getColor() { return color; }
   void addPiece(Piece* piece) { pieces.insert(piece); }
   void removePiece(Piece* piece) { pieces.erase(piece); }
};
