#pragma once

#include <set>

using namespace std;

class Player;
class Square;
class Move;

class Piece
{
protected:
   Player& player;
   Square* square;
   bool hasMoved;

public:

    Piece(Square* square, Player& player);

   Square* getSquare() const { return square; }
   Player& getPlayer() const { return player; }
   bool getHasMoved() const { return hasMoved; }
   virtual const char* getName() const = 0;
   virtual set<Square*> getMoves() const = 0;
   virtual Move* getMoveFromSquare(Square* destination);

   void setHasMoved() { hasMoved = true; }
   Move* moveToSquare(Square* square);
};


