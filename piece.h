#pragma once

#include <set>

using namespace std;

class Player;
class Square;
class Move;

/*
* PIECE
* Base class for a piece on the chess board.
*/
class Piece
{
protected:
   Player& player;   // The player that owns this piece. Will never be null.
   Square* square;   // The square this piece is currently on. Will never be null.
   bool hasMoved;    // Whether this piece has been moved.

public:

   // Constructor
   Piece(Square* square, Player& player);

   // Getters
   Square* getSquare() const { return square; }
   Player& getPlayer() const { return player; }
   bool getHasMoved() const { return hasMoved; }
   virtual const char getName() const = 0;                                       // Gets a unique name for this piece. Used to identify pieces and to generate move notations.
   virtual const Move* getMoveFromSquare(Square* destination);                   // Generates a Move object that describes how the piece would move to that square.
   virtual set<Square*> getMoves() const = 0;                                    // Gets all available moves for this piece.
   static bool canMoveToSquare(const Player& player, const Square* destination); // Check if the piece can move to the provided square.

   // Setters
   void setHasMoved() { hasMoved = true; }

   // Operations
   virtual void finishMove(const Move* move) {};   // Callback after a piece has moved. Used for special events like promotion.
   const Move* moveToSquare(Square* destination);  // Operation to move the piece to the provided square.
};


