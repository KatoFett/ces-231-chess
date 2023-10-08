#pragma once

#include <set>

using namespace std;

class Player;
class Square;

class Piece
{
protected:
   Player& player;
   Square& square;
   bool hasMoved;

public:

   Piece(Square& square, Player& player) :
      square(square), player(player), hasMoved(false)
   {}

   Square& getSquare() const { return square; }
   Player& getPlayer() const { return player; }
   bool getHasMoved() const { return hasMoved; }
   virtual const char* getName() const = 0;
   virtual set<Square> getMoves() const = 0;

   void setHasMoved() { hasMoved = true; }
   void moveToSquare(Square& square);
};


