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
   virtual const char getName() const = 0;
   virtual const Move* getMoveFromSquare(Square* destination);
   virtual set<Square*> getMoves() const = 0;
   virtual void finishMove(const Move* move) {};
   static bool canMoveToSquare(Player& player, Square* destination);

   void setHasMoved() { hasMoved = true; }

   const Move* moveToSquare(Square* destination);
};


