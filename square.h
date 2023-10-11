#pragma once

#include "direction.h"
#include <string>

using namespace std;

class Piece;

class Square
{
private:
   int index;
   Piece* piece;
   bool isDark;

public:
   Square(const bool isDark) :
      isDark(isDark), piece(nullptr), index(-1)
   {}

   bool operator == (const Square& rhs) const { return this == &rhs; }
   bool operator != (const Square& rhs) const { return this != &rhs; }
   bool operator < (const Square& rhs) const { return index < rhs.index; }

   int getIndex() const { return index; }
   int getRow() const;
   int getCol() const;
   Piece* getPiece() const { return piece; }
   bool getIsDark() const { return isDark; }
   string getNotation() const;
   Square* getLeft(const Direction direction) const;
   Square* getRight(const Direction direction) const;
   Square* getUp(const Direction direction) const;
   Square* getDown(const Direction direction) const;
   Square* getAdjacent(int dRow, int dCol);

   void setPiece(Piece* newPiece) { piece = newPiece; }
   void setIndex(const int newIdx) { index = newIdx; }
};


