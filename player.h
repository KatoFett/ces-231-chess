#pragma once
#include "piece.h"
#include "set"
#include <algorithm>

using namespace std;

class Player
{
private:
   Direction direction;
   int color[3];
   std::set<Piece&> pieces;
public:
   Player(Direction direction, int color[3]) :
      direction(direction), color()
   {
      copy_n(color, 3, this->color);
   }

   bool operator == (Player& rhs) { return this == &rhs; }
   bool operator != (Player& rhs) { return this != &rhs; }

   Direction getDirection() const { return direction; }
   int* getColor() { return color; }
   void addPiece(Piece& piece) { pieces.insert(piece); }
   void removePiece(Piece& piece) { pieces.erase(piece); }
};

enum Direction
{
   UP,
   DOWN,
   LEFT,
   RIGHT
};