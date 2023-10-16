#pragma once

#include "direction.h"
#include <string>

using namespace std;

class Piece;

/*
* SQUARE
* A square on the board.
*/
class Square
{
private:
   int index;     // The index of the square.
   Piece* piece;  // The piece on this square, if any.
   bool isDark;   // Whether this square is dark.

public:
   // Constructors
   Square(const bool isDark) :
      isDark(isDark), piece(nullptr), index(-1)
   {}

   // Operators
   bool operator == (const Square& rhs) const { return this == &rhs; }
   bool operator != (const Square& rhs) const { return this != &rhs; }
   bool operator < (const Square& rhs) const { return index < rhs.index; }

   // Getters
   int getIndex() const { return index; }
   int getRow() const;
   int getCol() const;
   Piece* getPiece() const { return piece; }
   bool getIsDark() const { return isDark; }
   string getNotation() const;
   Square* getLeft(const Direction direction, const int distance = 1) const;
   Square* getRight(const Direction direction, const int distance = 1) const;
   Square* getUp(const Direction direction, const int distance = 1) const;
   Square* getDown(const Direction direction, const int distance = 1) const;
   Square* getAdjacent(int dRow, int dCol) const;

   // Setters
   void setPiece(Piece* newPiece) { piece = newPiece; }
   void setIndex(const int newIdx) { index = newIdx; }
};
